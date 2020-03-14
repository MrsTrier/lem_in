#ifndef ERRORS_H

# define ERRORS_H

/*
** Lem-in message
*/

# define USAGE					"Usage: ./lem_in < MAP_FILE"

/*
** Read map
*/

# define ERR_INPUT			"ERROR: Wrong input format"

/*
** Parse
*/

# define ERR_INIT_OBJS			"ERROR: Can\'t initialize Lem-in"

# define ERR_ROOM_INIT			"ERROR: Can\'t initialize room"
# define ERR_ROOM_READ			"ERROR: Can\'t parse room"
# define ERR_ROOM_NAME_DUP		"ERROR: Input has room name duplicate"
# define ERR_ROOM_COORDS_DUP	"ERROR: Input has room coordinates duplicate"
# define ERR_START_END_ROOM		"ERROR: Input has no start or end room"

# define ERR_LINK_WITH_NO_ROOM	"ERROR: Can\'t create link with room which doesn't exist"
# define ERR_LINK_INIT			"ERROR: Can\'t initialize link"
# define ERR_LINK_READ			"ERROR: Can\'t parse link"
# define ERR_LINK_DUP			"ERROR: Input has link duplicate"
# define ERR_NO_LINKS			"ERROR: Input has no links"

# define ERR_LOC_INIT			"ERROR: Can\'t initialize location"
# define ERR_LOC_READ			"ERROR: Location parsing error"

# define ERR_TURN_INIT			"ERROR: Can\'t initialize turn"
# define ERR_NO_TURNS			"ERROR: Input has no turns"

/*
** Lem-in
*/

//# define ERR_QUEUE_INIT			"ERROR: Can\'t initialize queue"

# define ERR_PATH_INIT			"ERROR: Can\'t initialize path"
# define ERR_NO_PATH			"ERROR: Input has no path from start to end"

/*
** Visualizer message
*/

# define VS_USAGE				"Usage: ./lem-in < MAP_FILE | ./vs"

/*
** Visualizer
*/

# define ERR_BIG_MAP			"ERROR: Map is too big for processing"

# define ERR_ANT_INIT			"ERROR: Can\'t initialize ant"

# define ERR_VS_INIT			"ERROR: Can\'t initialize visualizer"

# define ERR_RECT_INIT			"ERROR: Can\'t initialize rect"

#endif
