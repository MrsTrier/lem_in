#ifndef VALIDATION_H
# define VALIDATION_H

# define			ANT (1 << 0)
# define			ROOMS (1 << 1)
# define			START (1 << 2)
# define			END (1 << 3)
# define			LINK (1 << 4)
# define			START_ROOM (1 << 5)
# define			END_ROOM (1 << 6)


# include "libft.h"
# include <stdio.h>
# include <stdbool.h>


typedef enum
{
	FIRST,
	MIDDLE,
	LAST
}	t_type;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	t_type			type;
	int				input_links;
	int				output_links;
	int				ant_number;
	struct s_room	*next;
}					t_room;

typedef struct		s_ant
{
    int				ant_index;
    t_type			type;
    t_room			*st_room;
    t_room			*room;
    struct s_ant	*next;
	int				move;
}					t_ant;

typedef struct		s_iter
{
    int				index;
    int				ants_num;
    t_ant			*ant;
    struct s_iter	*next;
}					t_iteration;

typedef struct		s_link
{
	t_room			*start;
	t_room			*end;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;


typedef struct		s_input
{
	int				ants_num;
	int				rooms_num;
	t_room			*room;
	char			*st_room;
	char			*nd_room;
	t_link			*link;
	int				start_room;
	int 			end_room;
	uint8_t			flag;
	t_iteration		*iteration;
	int				iter_num;
}					t_input;

/*
 * is_objtype.c
 * Functions to check if line contains needed info-type
 */
bool				is_room(char *line);
bool				is_link(char *line);
bool				is_ant_num(char *line);
bool				is_type_of_room(char *line);
bool				is_comment(char *line);

/*
 * free_funcs.c
 * Functions to free allocated memory
 */
void				free_room(t_input *input);
void				free_rooms(t_input *input);
void				free_links(t_input *input);
void				free_mem(char **objs, t_input *data);

/*
 * helper.c
 * Functions to call error & exit
 */
void				error_found(char *s);
int					count_objs(char	**objs);


/*
 * save_room.c
 */
void				save_room(t_room *room, t_input *input);

/*
 * save_link.c
 */
void				save_link(t_link **linklst, t_link *new_link);

/*
 * validation.c
 */
bool				room_exists(t_room *roomlst, char *name);
bool				duplicated_coords(t_room *roomlst, int x, int y);

/*
 * find_room.c
 */
t_room				*find_room(t_input *input, char *name);

/*
 * check_for_ant.c
 */
void				check_for_ant(char *input, t_input *data);

/*
 * check_for_type.c
 */
void				check_for_type(char *input, t_input *data);

/*
 * check_for_room.c
 */
void				check_for_room(char *input, t_input *data, char ***objs);

/*
 * check_for_link.c
 */
void				check_for_link(char *input, t_input *data, char ***objs);

/*
 * read_fd.c
 */
char				*read_fd(int fd);

/*
 * read_validate.c
 */
void				read_validate(char **res, t_input *data);

/*
 * validate_result.c
 */
void				validate_result(char *res, t_input *data);

#endif