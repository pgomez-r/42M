

#include "cub3d.h"

void	ft_invalid_map(int mode)
{
	if (mode == 1)
	{
		write (2, "Error: Invalid map\n", 19);
		exit (1);
	}
}
