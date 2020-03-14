# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshelia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 12:21:00 by vshelia           #+#    #+#              #
#    Updated: 2020/03/10 15:49:21 by vshelia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .c .o .h
.PHONY: all clean fclean re

NAME = lem-in
VS_NAME = vs
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2

RESET =\033[0m
BOLD =\033[1m
RED =\033[31m
GREEN =\033[32m
YELLOW =\033[33m

# **************************************************************************** #
#                         Includes and libraries variables                     #
# **************************************************************************** #
INCLUDE_DIR = include
INCLUDE_PARSING_LIST = parsing.h
INCLUDE_LEMIN_LIST = parsing.h lem_in.h
INCLUDE_VS_LIST = parsing.h
INCLUDE_PARSING = $(addprefix $(INCLUDE_DIR)/, $(INCLUDE_PARSING_LIST))
INCLUDE_LEMIN = $(addprefix $(INCLUDE_DIR)/, $(INCLUDE_LEMIN_LIST))
INCLUDE_VS = $(addprefix $(INCLUDE_DIR)/, $(INCLUDE_VS_LIST))

LIBFT_DIR = libft
SDL2_INCLUDE_DIR = $(HOME)/.brew/include
SDL2_LIB_DIR = $(HOME)/.brew/lib

INCLUDE_PROJ_HEADERS = -I $(INCLUDE_DIR) -I $(LIBFT_DIR)
INCLUDE_SDL2_HEADERS = -I $(SDL2_INCLUDE_DIR)

LINK_LIBFT = -L $(LIBFT_DIR) -lft
LINK_SDL2 = -L $(SDL2_LIB_DIR) -lSDL2 -lSDL2_ttf -lSDL2_image

OBJ_DIR = obj

# **************************************************************************** #
#                               parsing variables                              #
# **************************************************************************** #
SRC_PARSING_DIR = src/parsing
SRC_PARSING_LIST = read_farm.c                                                 \
				   validate_farm.c                                             \
				   build_farm.c                                                \
				   cmp_funcs.c lists.c clean_up.c

OBJ_PARSING_DIR = $(OBJ_DIR)/parsing
OBJ_PARSING_LIST = $(patsubst %.c,%.o,$(SRC_PARSING_LIST))
OBJ_PARSING = $(addprefix $(OBJ_PARSING_DIR)/, $(OBJ_PARSING_LIST))

# **************************************************************************** #
#                               lem-in variables                               #
# **************************************************************************** #
SRC_LEMIN_DIR = src/lem-in
SRC_LEMIN_LIST = main.c                                                        \
				 find_paths.c                                                  \
				 find_extra_paths.c                                            \
				 visit_links.c                                                 \
				 modify_farm.c                                                 \
				 choose_paths_set.c                                            \
				 ants_journey.c

OBJ_LEMIN_DIR = $(OBJ_DIR)/lem-in
OBJ_LEMIN_LIST = $(patsubst %.c,%.o,$(SRC_LEMIN_LIST))
OBJ_LEMIN = $(OBJ_PARSING) $(addprefix $(OBJ_LEMIN_DIR)/, $(OBJ_LEMIN_LIST))

# **************************************************************************** #
#                                vs variables                                  #
# **************************************************************************** #
SRC_VS_DIR = src/vs
SRC_VS_LIST =   animate_solution.c\
                create_iter.c\
                calc_sizes.c\
                check_for_ant.c\
                check_for_link.c\
                check_for_room.c\
                check_for_type.c\
                display_titles.c\
                display_ants.c\
                display_objs.c\
                find_cels_num.c\
                find_iter.c\
                find_room.c\
                free_funcs.c\
                helper.c\
                init_sdl.c\
                init_srfcandtxtrs.c\
                is_objtype.c\
                main.c\
                read_fd.c\
                read_validate.c\
                save_iter.c\
                save_link.c\
                save_room.c\
                validate_result.c\
                validation.c\

OBJ_VS_DIR = $(OBJ_DIR)/vs
OBJ_VS_LIST = $(patsubst %.c,%.o,$(SRC_VS_LIST))
OBJ_VS = $(OBJ_PARSING) $(addprefix $(OBJ_VS_DIR)/, $(OBJ_VS_LIST))



all:
	@make -C $(LIBFT_DIR)
	@make $(NAME)
	@make $(VS_NAME)
# **************************************************************************** #
#                                 libft making                                 #
# **************************************************************************** #
$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

# **************************************************************************** #
#                       Targets for creation obj directories                   #
# **************************************************************************** #
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_PARSING_DIR)

$(OBJ_LEMIN_DIR): $(OBJ_DIR)
	mkdir -p $(OBJ_LEMIN_DIR)

$(OBJ_VS_DIR): $(OBJ_DIR)
	mkdir -p $(OBJ_VS_DIR)

# **************************************************************************** #
#                           Targets for compilation                            #
# **************************************************************************** #
$(OBJ_PARSING_DIR)/%.o: $(SRC_PARSING_DIR)/%.c $(INCLUDE_PARSING)
	$(CC) $(CFLAGS) -c $< $(INCLUDE_PROJ_HEADERS) -o $@

$(OBJ_LEMIN_DIR)/%.o: $(SRC_LEMIN_DIR)/%.c $(INCLUDE_LEMIN)
	$(CC) $(CFLAGS) -c $< $(INCLUDE_PROJ_HEADERS) -o $@

$(OBJ_VS_DIR)/%.o: $(SRC_VS_DIR)/%.c $(INCLUDE_VS)
	$(CC) $(CFLAGS) -c $< $(INCLUDE_PROJ_HEADERS) $(INCLUDE_SDL2_HEADERS) -o $@

# **************************************************************************** #
#                             Targets for linking                              #
# **************************************************************************** #
$(NAME): $(LIBFT_DIR)/libft.a $(OBJ_LEMIN_DIR) $(OBJ_LEMIN)
	$(CC) $(CFLAGS) $(OBJ_LEMIN) -o $(NAME) $(LINK_LIBFT)
	@echo "$(GREEN)$(BOLD)$(NAME)$(RESET) $(GREEN)is created.$(RESET)"

$(VS_NAME): $(LIBFT_DIR)/libft.a $(OBJ_VS_DIR) $(OBJ_VS)
	$(CC) $(CFLAGS) $(OBJ_VS) -o $(VS_NAME) $(LINK_LIBFT) $(LINK_SDL2)
	@echo "$(GREEN)$(BOLD)$(VS_NAME)$(RESET) $(GREEN)is created.$(RESET)"

# **************************************************************************** #
#                             Targets for cleaning up                          #
# **************************************************************************** #
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Object files are removed.$(RESET)"

fclean: clean
	rm -f $(NAME) $(VS_NAME)
	rm -f $(LIBFT_DIR)/libft.a
	@echo "$(YELLOW)$(BOLD)Target$(RESET) $(YELLOW)files are removed.$(RESET)"

re: fclean all
