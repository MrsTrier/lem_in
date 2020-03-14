#ifndef ERRORS_H

# define ERRORS_H

/*
 * SDL errors
 */

# define ERR_INIT_SDL			"Failed to initialize SDL tools!"

/*
 * General
 */

# define ERR_READ_FD			"Error in reading a file descriptor \
(read_forvis.c)"
# define ERR_READ_FD_MEM		"Error in memory allocation (read_forvis.c)"

/*
** Lem-in message
*/

# define USAGE					"Usage: ./lem_in < MAP_FILE"

/*
** Read map
*/

# define ERR_INPUT				"ERROR: Wrong input format"

/*
** Parse
*/

# define ERR_ROOM_NAME_DUP		"ERROR: Input has room name duplicate"
# define ERR_ROOM_COORDS_DUP	"ERROR: Input has room coordinates duplicate"
# define ERR_START_END_ROOM		"ERROR: Input has mistakes in start or end \
															/room coordinates"
# define ERR_LINK_WITH_NO_ROOM	"ERROR: Can\'t create link with room which \
																/doesn't exist"
# define ERR_LINK_INIT			"ERROR: Can\'t initialize link"
# define ERR_LINK_DUP			"ERROR: Input has link duplicate"
# define ERR_NO_LINKS			"ERROR: Input has no links"
# define ERR_VS_INIT			"ERROR: Can\'t initialize visualizer"

#endif
