# FT_PRINTF

## Description

"ft_printf est un projet qui consiste a recoder une version simplifiee de la fonction printf de la libc. Il permet d'afficher differents types de donnees sur la sortie standard (comme des entiers, des chaines de caracteres, des caracteres, des pointeurs, etc.), tout en gerant des formats specifiques comme `%d`, `%s`, `%x`, `%p`, etc."

### Fonctionnalites 

Fonction principal permettant de print sur la sortie standard, a argument variable :

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

Permet le nombre variable d'arguments : 

```
stdarg.h
va_list	args;
va_start(args, format);
va_arg(args, int);
va_end(args);
```

- **va_list args** : Permet d'utiliser une liste d'arguments dans une fonction variadique.

- **va_start(args, format)** : Avant de pouvoir acceder aux arguments, il faut initialiser la `va_list` grace a cette macro prenant comme argument la `va_list` et le dernier argument avant la liste variadique.

- **va_arg(args, int)** : Cela permet d'acceder aux arguments suivants, chaque appel de celle-ci retourne un argument de type specifique qui est indiquee dans le dernier argument de la macro.

- **va_end(args)** : Une fois fini de traiter les arguments, il faut liberer les ressources alloues avec `va_end`.

Autrement le but global de la fonction ft_printf, est de boucler sur la string format, de detecter s'il y a un *%*, si c'est le cas d'appeler la fonction `print_format` afin d'ecrire sur la sortie standard selon le type de donnee. Autrement on se contente d'ecrire si c'est seulement des caracteres.
En cas d'erreur si la valeur retourne par write est = -1 et bien on return -1 pour la gestion d'erreur.

Print_format est un arbre de if permettant de d'ecrire selon le type de donnee. Comme dans la fonction ft_print, la valeur du write est stocke dans un count pour la gestion d'erreur.

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

#### Decomposition de print_format

Fonction qui ecrit un caractere sur la sortie standard.

```
int	print_char(char c)
{
	return (write(1, &c, 1));
}
```

Fonction qui ecrit une string sur la sortie standard. Utilisation de `ft_putstr_fd` permet l'utilisation de file descriptor afin d'ecrire sur la sortie voulue. Si str n'existe pas, il faut ecrire `(null)`.

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

Fonction permettant d'ecrire en format hexadecimal, etant le format de l'adresse des pointeurs.
Si le pointeur en question n'existe pas, comme pour la vraie fonction printf, il faut ecrire `(nil)`.
Il faut d'abord commencer par ecrire **0x** pour respecter le format des adresses. Sinon ce qui permet la conversion dans le format hexadecimal est la fonction `putbase`.

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

La fonction `putbase` est une fonction recursive qui convertit un nombre entier non signe (`unsigned long nb`) en une representation dans une base donnee `base` et l'affiche sur la sortie standard.

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

#### Parametres

- `unsigned long nb` : Le nombre a convertir et a afficher dans la base specifiee.

- `char *base` : La chaine de caracteres contenant les symboles de la base.

- `unsigned long size` : La taille de la base.

---------------------------------------------------------------------------------------------------------------------------------------

`tmp` est une variable local qui sera utilisee pour stocker le nombre de caracteres ecrits pendant l'execution de la fonction. Pourquoi ne pas stocker la valeur directement dans le count ? Le but etant de return le nombre exact de caracteres ecrit, si nous stockons la valeur directement dans count sachant que c'est une fonction recursive cela ecrasera le resultat a chaque appel de celle-ci , la solution etait de stocker dans une valeur tompon et de l'ajouter a count.

```
int tmp;
tmp = 0;
```

Si nb est plus grand que la taille de la base, la fonction s'appelle recursivement avec `nb / size`. Cela permet de diviser le nombre et de traiter les chiffres de maniere recursive, du plus significatif au moins significatif (de gauche a droite).

```
if (nb >= size)
	putbase(nb / size, base, size, count);
```


La valeur `nb % size` donne le chiffre correspondant dans la base actuelle, cela calcule le reste de la division de `nb` par `size`. Ce reste correspond au **chiffre** que l'on souhaite afficher dans la base.

```
tmp += write(1, &base[nb % size], 1);
```

#### Exemple

- Si on veut convertir de la base decimal a la base hexadecimal, admettons `nb = 255` et `size = 16` alors `nb % size` serait egal a `15`, 15 correspond a la lettre `F` du format hexadecimal (0123456789ABCDEF).


- `base` est une chaine de caracteres qui contient les symboles de la base.

- `base[nb % size]` utilise l'indice calcule precedemment pour acceder au caractere dans la chaine `base` qui correspond au chiffre `nb % size`.

```
&base[nb % size]
```

Fonction permettant d'afficher les int. Le format est similaire a `print_hex`, a la difference qu'on traite le cas des nombres negatifs, en faisant une inversion de valeur avec `nb = -nb` et qu'on write le `-` pour afficher que c'est negatif. Sinon putbase est utilise de nouveau pour ecrire sur la sortie standard.

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
