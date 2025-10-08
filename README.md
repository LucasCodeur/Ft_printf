# FT_PRINTF

## Description

`ft_printf` is a project that consists of recoding a simplified version of the `printf` function from the **libc**.
It allows displaying different types of data on the standard output (such as integers, strings, characters, pointers, etc.), while handling specific formats like `%d`, `%s`, `%x`, `%p`, and so on.

---

### Features

Main function that prints to the standard output with a variable number of arguments:

```
int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	if (format == 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, args);
		else
			count += write(1, format, 1);
		if (count == -1)
			return (-1);
		++format;
	}
	va_end(args);
	return (count);
}
```

This function supports a variable number of arguments:

```
stdarg.h
va_list	args;
va_start(args, format);
va_arg(args, int);
va_end(args);
```

* **va_list args** : Used to handle a list of arguments in a variadic function.
* **va_start(args, format)** : Initializes the `va_list` before accessing the arguments, taking as parameters the list and the last fixed argument before the variadic ones.
* **va_arg(args, int)** : Accesses the next argument in the list, returning it as the specified type.
* **va_end(args)** : Cleans up the list when finished.

The main purpose of `ft_printf` is to loop through the `format` string, detect if there is a `%`, and if so, call the `print_format` function to print the corresponding type on the standard output.
Otherwise, it simply writes the character.

If an error occurs (for example, if `write` returns `-1`), the function returns `-1` for proper error handling.

`print_format` is a chain of conditional checks that writes data depending on its type. Like in `ft_printf`, the number of written characters is stored in `count` to manage errors.

```
static int	print_format(char format, va_list args)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'p')
		count += print_hex(va_arg(args, void *), "0123456789abcdef", 16);
	else if (format == 'd')
		count += print_nbr(va_arg(args, int), "0123456789abcdef", 10);
	else if (format == 'u')
		count += print_nbr(va_arg(args, unsigned int), "0123456789abcdef", 10);
	else if (format == 'i')
		count += print_nbr(va_arg(args, int), "0123456789abcdef", 10);
	else if (format == 'x')
		count += print_nbr(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (format == 'X')
		count += print_nbr(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (format == '%')
		count += write(1, "%", 1);
	return (count);
}
```

---

#### Breakdown of `print_format`

**Function that writes a single character to the standard output:**

```
int	print_char(char c)
{
	return (write(1, &c, 1));
}
```

**Function that writes a string to the standard output:**

The use of `ft_putstr_fd` allows writing to a specific file descriptor.
If `str` is null, the function writes `(null)`.

```
int	print_str(char *str)
{
	int		count;

	count = 0;
	if (!str)
	{
		count += ft_putstr_fd("(null)", 1);
		if (count == -1)
			return (-1);
		return (6);
	}
	count += ft_putstr_fd(str, 1);
	return (count);
}
```

**Function that writes a pointer in hexadecimal format:**

If the pointer is null, the function writes `(nil)` (just like the real `printf`).
Otherwise, it first writes `0x` and then converts the address to hexadecimal using `putbase`.

```
int	print_hex(void *p, char *base, long size)
{
	int		count;

	count = 0;
	if (!p)
	{
		count = ft_putstr_fd("(nil)", 1);
		if (count == -1)
			return (-1);
		return (5);
	}
	count += ft_putstr_fd("0x", 1);
	if (count == -1)
		return (-1);
	putbase((unsigned long)p, base, size, &count);
	return (count);
}
```

---

### Function `putbase`

This recursive function converts an unsigned integer (`unsigned long nb`) into the given base (`base`) and writes it to the standard output.

```
void	putbase(unsigned long nb, char *base, unsigned long size, int *count)
{
	int	tmp;

	tmp = 0;
	if (nb >= size)
		putbase(nb / size, base, size, count);
	tmp += write(1, &base[nb % size], 1);
	*count += tmp;
	if (tmp == -1)
	{
		*count = tmp;
		return ;
	}
}
```

#### Parameters

* `unsigned long nb` : The number to convert and print.
* `char *base` : The string containing the symbols of the base.
* `unsigned long size` : The size of the base.

---

`tmp` is a local variable used to store the number of characters written during the execution of the function.
We don’t write directly into `count` because the function is recursive — doing so would overwrite previous results.
Instead, we use `tmp` as a temporary buffer and add it to `count` after each call.

If `nb` is greater than or equal to `size`, the function calls itself with `nb / size` to process digits from the most significant to the least significant (left to right).

Then `nb % size` gives the digit to display in the current base.

---

#### Example

If we want to convert from decimal to hexadecimal, for example `nb = 255` and `size = 16`, then `nb % size` equals `15`, which corresponds to the letter `F` in hexadecimal (`0123456789ABCDEF`).

`base[nb % size]` accesses the character corresponding to that value in the base string.

---

### Function `print_nbr`

This function prints integers.
It works similarly to `print_hex`, except it handles negative numbers:
if `nb` is negative, the function writes the `-` sign and then flips the number to positive before calling `putbase`.

```
int	print_nbr(long nb, char *base, long size)
{
	int	count;

	count = 0;
	if (nb < 0 && size == 10)
	{
		nb = -nb;
		count += write(1, "-", 1);
		if (count == -1)
			return (-1);
	}
	putbase(nb, base, size, &count);
	return (count);
}
```
---

# FT_PRINTF

## Description

`ft_printf` est un projet qui consiste à recoder une version simplifiée de la fonction `printf` de la **libc**.
Il permet d’afficher différents types de données sur la sortie standard (comme des entiers, des chaînes de caractères, des caractères, des pointeurs, etc.), tout en gérant des formats spécifiques comme `%d`, `%s`, `%x`, `%p`, etc.

---

### Fonctionnalités

Fonction principale permettant d’afficher sur la sortie standard, avec un nombre variable d’arguments :

```
int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	if (format == 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, args);
		else
			count += write(1, format, 1);
		if (count == -1)
			return (-1);
		++format;
	}
	va_end(args);
	return (count);
}
```

Permet la gestion d’un nombre variable d’arguments :

```
stdarg.h
va_list	args;
va_start(args, format);
va_arg(args, int);
va_end(args);
```

* **va_list args** : Permet de stocker la liste des arguments d’une fonction variadique.
* **va_start(args, format)** : Initialise la `va_list` avant d’accéder aux arguments, en précisant le dernier argument fixe avant la liste variadique.
* **va_arg(args, int)** : Permet d’accéder aux arguments suivants. Chaque appel renvoie un argument du type spécifié.
* **va_end(args)** : Libère les ressources associées à la `va_list` une fois le traitement terminé.

Le but global de `ft_printf` est de parcourir la chaîne `format`, de détecter la présence d’un `%`, et, le cas échéant, d’appeler la fonction `print_format` pour écrire sur la sortie standard selon le type de donnée.
Sinon, la fonction écrit simplement le caractère courant.

En cas d’erreur (si `write` retourne `-1`), la fonction renvoie `-1` pour signaler l’échec.

`print_format` est une série de conditions permettant d’écrire le bon type de donnée. Comme dans `ft_printf`, la valeur retournée par `write` est stockée dans une variable `count` afin de gérer les erreurs.

```
static int	print_format(char format, va_list args)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'p')
		count += print_hex(va_arg(args, void *), "0123456789abcdef", 16);
	else if (format == 'd')
		count += print_nbr(va_arg(args, int), "0123456789abcdef", 10);
	else if (format == 'u')
		count += print_nbr(va_arg(args, unsigned int), "0123456789abcdef", 10);
	else if (format == 'i')
		count += print_nbr(va_arg(args, int), "0123456789abcdef", 10);
	else if (format == 'x')
		count += print_nbr(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (format == 'X')
		count += print_nbr(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (format == '%')
		count += write(1, "%", 1);
	return (count);
}
```

---

#### Décomposition de `print_format`

**Fonction qui écrit un caractère sur la sortie standard :**

```
int	print_char(char c)
{
	return (write(1, &c, 1));
}
```

**Fonction qui écrit une chaîne sur la sortie standard :**

L’utilisation de `ft_putstr_fd` permet d’écrire sur un descripteur de fichier.
Si la chaîne `str` est nulle, la fonction écrit `(null)`.

```
int	print_str(char *str)
{
	int		count;

	count = 0;
	if (!str)
	{
		count += ft_putstr_fd("(null)", 1);
		if (count == -1)
			return (-1);
		return (6);
	}
	count += ft_putstr_fd(str, 1);
	return (count);
}
```

**Fonction qui écrit un pointeur en format hexadécimal :**

Si le pointeur est nul, la fonction écrit `(nil)` comme le vrai `printf`.
Sinon, elle commence par écrire `0x`, puis convertit l’adresse en hexadécimal à l’aide de `putbase`.

```
int	print_hex(void *p, char *base, long size)
{
	int		count;

	count = 0;
	if (!p)
	{
		count = ft_putstr_fd("(nil)", 1);
		if (count == -1)
			return (-1);
		return (5);
	}
	count += ft_putstr_fd("0x", 1);
	if (count == -1)
		return (-1);
	putbase((unsigned long)p, base, size, &count);
	return (count);
}
```

---

### Fonction `putbase`

Cette fonction récursive convertit un entier non signé (`unsigned long nb`) dans une base donnée (`base`) et l’affiche sur la sortie standard.

```
void	putbase(unsigned long nb, char *base, unsigned long size, int *count)
{
	int	tmp;

	tmp = 0;
	if (nb >= size)
		putbase(nb / size, base, size, count);
	tmp += write(1, &base[nb % size], 1);
	*count += tmp;
	if (tmp == -1)
	{
		*count = tmp;
		return ;
	}
}
```

#### Paramètres

* `unsigned long nb` : Nombre à convertir et afficher.
* `char *base` : Chaîne contenant les symboles de la base.
* `unsigned long size` : Taille de la base.

---

`tmp` est une variable locale servant à stocker le nombre de caractères écrits à chaque appel.
On ne peut pas écrire directement dans `count`, car la fonction est récursive — cela écraserait la valeur précédente.
On stocke donc le résultat dans `tmp` avant de l’ajouter à `count`.

Si `nb` est supérieur ou égal à `size`, la fonction s’appelle elle-même avec `nb / size` pour traiter les chiffres de gauche à droite.

`nb % size` correspond ensuite au chiffre à afficher dans la base choisie.

---

#### Exemple

Pour convertir un nombre de la base décimale à l’hexadécimal :
Si `nb = 255` et `size = 16`, alors `nb % size = 15`, ce qui correspond à la lettre `F` dans la base hexadécimale (`0123456789ABCDEF`).

`base[nb % size]` permet d’accéder au caractère correspondant dans la chaîne `base`.

---

### Fonction `print_nbr`

Fonction qui affiche des entiers.
Le fonctionnement est similaire à `print_hex`, à la différence qu’on gère les nombres négatifs :
si `nb` est négatif, on écrit le signe `-` puis on inverse la valeur avant d’appeler `putbase`.

```
int	print_nbr(long nb, char *base, long size)
{
	int	count;

	count = 0;
	if (nb < 0 && size == 10)
	{
		nb = -nb;
		count += write(1, "-", 1);
		if (count == -1)
			return (-1);
	}
	putbase(nb, base, size, &count);
	return (count);
}
```

---
