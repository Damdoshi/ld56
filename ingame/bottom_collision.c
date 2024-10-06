
#include		"program.h"

bool			ingame_bottom_collision(t_ingame	*ing,
						t_unit		*unit)
{
  int			startx = unit->area.x - unit->area.w / 2;
  int			endx = unit->area.x + unit->area.w / 2;

  for (int i = startx; i < endx; ++i)
    if (ingame_get_pixel(ing, i, unit->area.y + 1) != AIR)
      return (true);
  return (false);
}

