# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:07:32 by lud-adam          #+#    #+#              #
#    Updated: 2024/11/22 16:39:27 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Werror -Wextra 

# Source files
SRC = \
	ft_atoi.c     ft_isascii.c  ft_memcmp.c      ft_putendl_fd.c ft_strdup.c    ft_strlen.c   ft_strtrim.c	\
	ft_bzero.c    ft_isdigit.c  ft_memcpy.c      ft_putnbr_fd.c  ft_striteri.c  ft_strmapi.c  ft_substr.c	\
	ft_calloc.c   ft_isprint.c  ft_memmove.c     ft_putstr_fd.c  ft_strjoin.c   ft_strncmp.c  ft_tolower.c \
	ft_isalnum.c  ft_itoa.c     ft_memset.c      ft_split.c      ft_strlcat.c   ft_strnstr.c  ft_toupper.c \
	ft_isalpha.c  ft_memchr.c   ft_putchar_fd.c  ft_strchr.c     ft_strlcpy.c   ft_strrchr.c

SRC_BONUS := \
	ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c ft_lstlast_bonus.c	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c

# Object and dependency files
OBJ := $(SRC:.c=.o)
OBJ_BONUS :=  $(SRC_BONUS:.c=.o) $(OBJ)

%.o: %.c libft.h 
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) 
	ar -rcs $(NAME) $^

bonus: $(OBJ_BONUS)
	@$(MAKE) --no-print-directory OBJ="$(OBJ_BONUS)"

clean:
	rm -rf *.o 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
