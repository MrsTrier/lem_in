cmake_minimum_required(VERSION 3.15)
project(my_visual C)

set(CMAKE_C_STANDARD 11)

include_directories(visualisation/includes)
include_directories(visualisation/libft/includes)

include_directories(~/Library/Frameworks/SDL2.framework/Headers)
include_directories(~/Library/Frameworks/SDL2_image.framework/Headers)
include_directories(~/Library/Frameworks/SDL2_ttf.framework/Headers)

add_executable(my_visual
    visualisation/includes/errors.h
    visualisation/includes/validation.h
    visualisation/includes/visualization.h
    visualisation/libft/includes/get_next_line.h
    visualisation/libft/includes/libft.h
    visualisation/libft/ft_any.c
    visualisation/libft/ft_atoi.c
    visualisation/libft/ft_bzero.c
    visualisation/libft/ft_count_if.c
    visualisation/libft/ft_create_elem.c
    visualisation/libft/ft_freetwodarr.c
    visualisation/libft/ft_isalnum.c
    visualisation/libft/ft_isalpha.c
    visualisation/libft/ft_isascii.c
    visualisation/libft/ft_isdigit.c
    visualisation/libft/ft_isprint.c
    visualisation/libft/ft_itoa.c
    visualisation/libft/ft_list_at.c
    visualisation/libft/ft_lstadd.c
    visualisation/libft/ft_lstdel.c
    visualisation/libft/ft_lstdelone.c
    visualisation/libft/ft_lstiter.c
    visualisation/libft/ft_lstmap.c
    visualisation/libft/ft_lstnew.c
    visualisation/libft/ft_memalloc.c
    visualisation/libft/ft_memccpy.c
    visualisation/libft/ft_memchr.c
    visualisation/libft/ft_memcmp.c
    visualisation/libft/ft_memcpy.c
    visualisation/libft/ft_memdel.c
    visualisation/libft/ft_memmove.c
    visualisation/libft/ft_memset.c
    visualisation/libft/ft_putchar.c
    visualisation/libft/ft_putchar_fd.c
    visualisation/libft/ft_putendl.c
    visualisation/libft/ft_putendl_fd.c
    visualisation/libft/ft_putnbr.c
    visualisation/libft/ft_putnbr_fd.c
    visualisation/libft/ft_putstr.c
    visualisation/libft/ft_putstr_fd.c
    visualisation/libft/ft_reverse.c
    visualisation/libft/ft_strcat.c
    visualisation/libft/ft_strchr.c
    visualisation/libft/ft_strclr.c
    visualisation/libft/ft_strcmp.c
    visualisation/libft/ft_strcpy.c
    visualisation/libft/ft_strdel.c
    visualisation/libft/ft_strdup.c
    visualisation/libft/ft_strequ.c
    visualisation/libft/ft_striter.c
    visualisation/libft/ft_striteri.c
    visualisation/libft/ft_strjoin.c
    visualisation/libft/ft_strlcat.c
    visualisation/libft/ft_strlen.c
    visualisation/libft/ft_strmap.c
    visualisation/libft/ft_strmapi.c
    visualisation/libft/ft_strncat.c
    visualisation/libft/ft_strncmp.c
    visualisation/libft/ft_strncpy.c
    visualisation/libft/ft_strnequ.c
    visualisation/libft/ft_strnew.c
    visualisation/libft/ft_strnstr.c
    visualisation/libft/ft_strrchr.c
    visualisation/libft/ft_strsplit.c
    visualisation/libft/ft_strstr.c
    visualisation/libft/ft_strsub.c
    visualisation/libft/ft_strtrim.c
    visualisation/libft/ft_tolower.c
    visualisation/libft/ft_toupper.c
    visualisation/libft/get_next_line.c
    visualisation/libft/is_int.c
    visualisation/sources/validation/calc_sizes.c
    visualisation/sources/validation/check_for_ant.c
    visualisation/sources/validation/check_for_link.c
    visualisation/sources/validation/check_for_room.c
    visualisation/sources/validation/check_for_type.c
    visualisation/sources/validation/display_ants.c
    visualisation/sources/validation/display_links.c
    visualisation/sources/validation/display_rooms.c
    visualisation/sources/validation/find_cels_num.c
    visualisation/sources/validation/find_iter.c
    visualisation/sources/validation/find_room.c
    visualisation/sources/validation/free_funcs.c
    visualisation/sources/validation/helper.c
    visualisation/sources/validation/init_sdl.c
    visualisation/sources/validation/init_srfcandtxtrs.c
    visualisation/sources/validation/is_objtype.c
    visualisation/sources/validation/main.c
    visualisation/sources/validation/read_fd.c
    visualisation/sources/validation/read_validate.c
    visualisation/sources/validation/save_link.c
    visualisation/sources/validation/save_room.c
    visualisation/sources/validation/validate_result.c
    visualisation/sources/validation/validation.c
    visualisation/sources/validation/animate_solution.c
    visualisation/sources/validation/calc_additional_metrics.c
    visualisation/sources/validation/save_iter.c)

target_link_libraries(my_visual "-framework SDL2")
target_link_libraries(my_visual "-framework SDL2_image")
target_link_libraries(my_visual "-framework SDL2_ttf")
set_target_properties(my_visual PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")