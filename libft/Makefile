# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshelia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 12:37:42 by vshelia           #+#    #+#              #
#    Updated: 2020/03/10 15:48:42 by vshelia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .c .o .h
.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2

RESET =\033[0m
BOLD =\033[1m
RED =\033[31m
GREEN =\033[32m
YELLOW =\033[33m

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c            \
	  ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c          \
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c    \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c        \
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c  \
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c         \
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c          \
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c         \
	  ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_sqrt.c \
	  ft_isspace.c ft_realloc.c ft_str_toupper.c ft_str_tolower.c              \
	  ft_str_isnumber.c ft_atoll.c ft_error.c ft_free_strsplit.c               \
	  get_next_line.c get_next_line_n.c ft_putchar_esc.c                       \
	  ft_printf.c                                                              \
	  ft_printf_parser.c ft_printf_operation_definer.c                         \
	  ft_ctoa.c ft_lltoa.c ft_ulltoa_base.c ft_atoull.c                        \
	  ft_printf_integers.c ft_printf_floats.c ft_printf_asterisk_handler.c     \
	  ft_printf_formatting.c ft_printf_formatting_extra.c ft_printf_rounder.c  \
	  ft_printf_replace_by_esc.c ft_printf_non_to_printable.c                  \
	  ft_printf_utilities.c                                                    \
	  ft_avl_tree_new.c ft_avl_tree_insert.c ft_avl_tree_rotations.c           \
	  ft_avl_tree_inorder.c ft_avl_tree_postorder.c ft_avl_tree_preorder.c     \
	  ft_avl_tree_search.c
OBJ = $(patsubst %.c,%.o,$(SRC))
HDR = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $?
	ranlib $(NAME)
	@echo "$(GREEN)$(BOLD)libft.a$(RESET) $(GREEN)is created.$(RESET)"

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
