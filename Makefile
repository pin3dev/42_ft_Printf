# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 23:01:52 by ivbatist          #+#    #+#              #
#    Updated: 2024/09/21 01:10:38 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST_EXEC = testprintf

################################################################################
# 						Compiler and Flags	Variables						   #
################################################################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc
RM = rm -f
RMD = rm -rf

################################################################################
# 							Dir	Path	Variables 							   #
################################################################################

SRCDIR = src
OBJDIR = obj
INCDIR = inc
TESTDIR = test

################################################################################
# 							Files	Path	Variables 						   #
################################################################################

SRC =   $(SRCDIR)/ft_printf.c \
        $(SRCDIR)/ft_print_hex.c \
        $(SRCDIR)/ft_print_pointer.c \
        $(SRCDIR)/ft_print_unsig.c \
		$(SRCDIR)/utils.c \

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

################################################################################
# 							Libft Variables 								   #
################################################################################

LIBFT_DIR = libft/libft 
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = git@github.com:pin3dev/42_Libft.git

################################################################################
# 							Manual	Targets		 							   #
################################################################################

all: $(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RMD) $(OBJDIR)
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME) 
	@$(RM) $(TEST_EXEC) 
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RMD) libft
	@echo "$(NAME) removed"

re: fclean all

################################################################################
# 							Test Target 		 							   #
################################################################################

test: all
	@$(CC) -o $(TEST_EXEC) $(TESTDIR)/main.c -L. -lftprintf -L$(LIBFT_DIR) -lft
	@echo "Running tests..."
	@./$(TEST_EXEC)

################################################################################
# 						Test Targets by @alelievr	 						   #
################################################################################

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Build completed"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@if [ ! -d libft ]; then \
		echo "Cloning libft from pin3dev repo..."; \
		git clone $(LIBFT_REPO) libft; \
	fi
	@$(MAKE) -C $(LIBFT_DIR) 

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Linking only Mandatory Library into $(NAME)"

################################################################################
# 										PS		 	 						   #
################################################################################

.PHONY: all clean fclean re
