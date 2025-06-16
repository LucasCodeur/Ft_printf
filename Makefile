# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 10:37:40 by lud-adam          #+#    #+#              #
#    Updated: 2024/12/20 11:03:49 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC := ft_printf.c ft_printf_utils.c
OBJ := $(SRC:.c=.o)
H_FILES := ft_printf.h
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME) 

$(NAME): $(OBJ) 
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(H_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f *.a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
