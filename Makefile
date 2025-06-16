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

all: lib $(NAME) 

$(NAME): $(OBJ) 
	cp $(LIBFT) . 
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(H_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

lib: 
	$(MAKE) -C $(LIBFT_DIR) -j

clean:
	rm -f *.o
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

