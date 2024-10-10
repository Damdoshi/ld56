
#include		"program.h"

bool			ingame_traversable(t_ingame	*ingame,
					   int		x,
					   int		y)
{
  int			ret;

  ret = ingame_get_pixel(ingame, x, y);
  return (ret == AIR || ret == WATER || ret == WATER_SOURCE || ret == WATER_WALL || ret == WATER_DEATH || ret == VICTORY || ret == DEATH);
}

