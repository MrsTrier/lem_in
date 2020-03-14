/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:21:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 15:23:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"

# define NOA BOLD "number_of_ants" RESET
# define TR BOLD "the_rooms" RESET
# define TL BOLD "the_links" RESET

# define UNICODE_ANT "\xF0\x9F\x90\x9C"
# define UNICODE_ROOM "\xF0\x9F\x8F\x9B"
# define UNICODE_LINK "\xF0\x9F\x94\x97"

# define FACE_LOOK_DOWN "\xE3\x83\x8E( \xE3\x82\x9C-\xE3\x82\x9C\xE3\x83\x8E)"
# define FACE_LOOK_FRONT "\xE3\x83\x8E( \xC2\xBA _ \xC2\xBA\xE3\x83\x8E)"
# define WALL "\xE2\x94\xAC\xE2\x94\xB4\xE2\x94\xAC\xE2\x94\xB4"
# define FACE_BEHIND_WALL WALL "\xE2\x94\xA4  (\xE0\xB2\xA0\xE2\x94\x9C" WALL

# define ERR_N_E_S FACE_LOOK_DOWN " expected symbol was not found! "
# define ERR_NO_EXPECTED_SYMB ERR_N_E_S FACE_LOOK_FRONT

# define ERR_EMPTY_INPUT "no input whatsoever"

# define ERR_ONLY_COMMENTS "only comments found"

# define ERR_ANT_0 "not valid " NOA
# define ERR_ANT_SIGN "sign in " NOA
# define ERR_ANT_LAST_STR "input format is not respected"
# define ERR_ANT_MANY_SYMB "too many symbols in " NOA
# define ERR_ANT_NOT_DIGIT NOA " can only consist of digits"
# define ERR_ANT_GREATER_MAX NOA " is greater than INT_MAX"

# define ERR_ROOM_NO_DASH ERR_ANT_LAST_STR
# define ERR_ROOM_WRONG_SPACES "wrong spaces in " TR " declaration"
# define ERR_ROOM_L TR " can't start with 'L' symbol"
# define ERR_ROOM_SPACE TR " can't start with space"
# define ERR_ROOM_NON_PRIN TR " can't have non-printable characters"
# define ERR_ROOM_LARGE_COORD "too many symbols in " TR " coordinate"
# define ERR_ROOM_ND_C TR " coordinates can only consist of digits"
# define ERR_ROOM_GRTR_MAX TR " coordinate is greater than INT_MAX"
# define ERR_ROOM_NON_UNIQUE TR " names must be unique"
# define ERR_ROOM_LIMIT TR " amount can't be more than " S_ROOMS_LIMIT

# define ERR_LINK_NO_LF TL " must end with newline"
# define ERR_LINK_NO_F_ROOM "no first room in " TL " declatation"
# define ERR_LINK_NO_S_ROOM "no second room in " TL " declatation"
# define ERR_LINK_NON_PRIN " non-printable characters in " TL " declaration"
# define ERR_LINK_F_N_P "first room's name has" ERR_LINK_NON_PRIN
# define ERR_LINK_S_N_P "second room's name has dash or" ERR_LINK_NON_PRIN
# define ERR_LINK_NOT_EXIST "wrong room's name in " TL " declatation"
# define ERR_LINK_LIMIT TL " amount per room can't be more than " S_L_L
# define ERR_LINK_SAME "room can't have a link to itself"
# define ERR_LINK_EXIST "link does already exist in " TL " declaration"

# define ERR_NO_START "##start room is not defined"
# define ERR_NO_END "##end room is not defined"

# define ERR_MULT_START "##start can only be used once"
# define ERR_MULT_END "##end can only be used once"

# define ERR_ROOM_DUP_COORDS TR " coordinates must be unique"

# define BUF64KB 65536

# define ROOMS_LIMIT 50002
# define S_ROOMS_LIMIT "50002"
# define LINKS_LIMIT 50002
# define S_LINKS_LIMIT "50002"
# define S_L_L S_LINKS_LIMIT

typedef struct	s_lst
{
	void			*content;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_room
{
	char			*name;
	char			position;
	unsigned int	coord_x;
	unsigned int	coord_y;
	t_avl_tree		*links;
	t_lst			*nodes_list;
	int				has_preferable_link;
	int				preferable_was_used;
	unsigned int	amount_of_links;
	unsigned int	visited;
	t_lst			*predecessor;
	int				was_in_another_queue;
}				t_room;

typedef struct	s_link
{
	t_room	*room;
	int		edge_weight;
}				t_link;

typedef struct	s_path
{
	t_lst			*path;
	unsigned int	length;
	unsigned int	shorter_paths_amount;
	unsigned int	sum_of_shorter_paths_length;
	unsigned int	priority_value;
	unsigned int	ants_on_path;
	unsigned int	steps_to_move;
}				t_path;

typedef struct	s_farm
{
	char		*map;
	t_avl_tree	*farm;
	t_lst		*nodes_list;
	unsigned	number_of_rooms;
	t_room		*start_room;
	t_room		*end_room;
	t_lst		*set_of_paths;
	t_lst		*sets_of_paths;
	unsigned	number_of_ants;
	unsigned	steps_counted;
}				t_farm;

char			*g_map;

void			lst_push(t_lst **list, void *content, char position);
void			lst_del(t_lst **list, char position);
t_lst			*postorder_list_of_nodes(t_avl_tree *node);
void			create_links_nodes_lists(t_lst *nodes_list);

void			error(const char *msg, const char *str);
char			*strchr_until(const char *str, int c, const char *end);
char			*read_fd(int fd);

int				cmp_t_rooms(void *a, void *b);
int				cmp_str_t_room(void *a, void *b);
int				cmp_t_links(void *a, void *b);
int				cmp_str_t_link(void *a, void *b);
char			handle_command(char *map);

void			set_number_of_ants(t_farm *farm, char **map);
char			*find_dash_line(char *str);
unsigned int	set_room_coordinate(char *start, char *end);
char			*create_room_name(char *parse_str, char *str_end,
				char **space_1, char **space_2);

void			parse_links_names(char *parse_str, char *str_end, char **names);

void			check_duplicate_coordinates(t_lst *nodes_list);

void			build_farm(t_farm *farm);

void			free_farm(t_farm *farm);
void			free_set_of_paths(t_lst **set_of_paths);

#endif
