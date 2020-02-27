NAME = lem_in
VS_NAME = vs

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lft -L$(LIBFT_DIRECTORY) -L$(SDL_LIBRARY) -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(SDL_HEADERS)

SDL_LIBRARY = $(HOME)/.brew/lib
SDL_HEADERS = $(HOME)/.brew/include

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

HEADERS_LIST = validation.h

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/validation/

# SOURCES_LIST = main.c

# SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# LI_SOURCES_LIST = lem_in.c
# LI_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(LI_SOURCES_LIST))

VS_SOURCES_LIST = animate_solution.c\
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

VS_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(VS_SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(VS_SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# LI_OBJECTS_LIST = $(patsubst %.c, %.o, $(LI_SOURCES_LIST))
# LI_OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(LI_OBJECTS_LIST))
#
# VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(VS_SOURCES_LIST))
# VS_OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(VS_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(VS_NAME)
# $(NAME)

# $(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(LI_OBJECTS) $(OBJECTS)
# 	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(LI_OBJECTS) $(OBJECTS) -o $(NAME)
# 	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
# 	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

# $(VS_NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(VS_OBJECTS) $(OBJECTS)
# 	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(VS_OBJECTS) $(OBJECTS) -o $(VS_NAME)
# 	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
# 	@echo "$(NAME): $(GREEN)$(VS_NAME) was created$(RESET)"

$(VS_NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(VS_NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(VS_NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(VS_NAME)
	@echo "$(NAME): $(RED)$(VS_NAME) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all