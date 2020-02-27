#include "libft.h"

void	ft_free_strsplit(char **arr)
{
	while (*arr != NULL)
	{
		free(*arr);
		(arr)++;
	}
}
