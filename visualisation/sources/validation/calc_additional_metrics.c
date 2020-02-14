# include "validation.h"
# include "errors.h"
# include "visualization.h"

void	calc_additional_metrics(t_sizes *sizes)
{
	sizes->ant_w = sizes->room_width / 3.333;
	sizes->ant_h = sizes->ant_w / 0.7;
}