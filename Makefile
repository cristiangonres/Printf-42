# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cristian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 19:09:13 by cristian          #+#    #+#              #
#    Updated: 2023/07/29 12:21:54 by cristian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB= ar rcs
NAME=libftprintf.a
CC=gcc
FLAGS=-Wall -Wextra -Werror
SRC= libftprintf.c libftprintf_hex.c libftprintf_nbr.c libftprintf_str.c libftprintf_ptr.c libftprintf_unsig.c 
OBJ= $(SRC:.c=.o)
INCLUDE = ft_printf.h
all: $(NAME)
RM=/bin/rm -f
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all