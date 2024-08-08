# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 23:01:52 by ivbatist          #+#    #+#              #
#    Updated: 2022/12/23 23:32:54 by ivbatist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =   ft_putchar.c ft_putstr.c ft_printf.c ft_print_hex.c ft_print_pointer.c \
                        ft_print_unsig.c ft_putnbr.c

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@
	@echo "[OK] Build completed"

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@echo "[Success] Done the compilation Printf"
clean:
	@rm -f $(OBJ)
	@echo "[Deleting] Object files deleted"

fclean: clean
	@rm -f $(NAME) 
	@echo "[Deleting] Printf.a deleted"

re: fclean all

.PHONY: all clean fclean re
