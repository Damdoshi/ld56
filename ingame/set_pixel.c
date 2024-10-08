
#include		"program.h"

void			ingame_set_pixel(t_ingame	*ing,
					 int		x,
					 int		y,
					 int		t)
{
  if (x < 0 || y < 0 || x >= ing->map_size.x || y >= ing->map_size.y)
    return ;
  ing->physic_map[x + ing->map_size.x * y] = t;
}

