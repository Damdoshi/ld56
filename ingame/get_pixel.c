
#include		"program.h"

int			ingame_get_pixel(t_ingame	*ing,
					 int		x,
					 int		y)
{
  if (x < 0 || y < 0 || x >= ing->map_size.x || x >= ing->map_size.y)
    return (ROCK);
  return (ing->physic_map[x + ing->map_size.x * y]);
}

