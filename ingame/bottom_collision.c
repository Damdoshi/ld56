
#include		"program.h"

bool			ingame_bottom_collision(t_ingame	*ing,
						t_unit		*unit,
						bool		wider)
{
  int			startx = ceil(unit->area.x - unit->area.w / 2.0);
  int			endx = floor(unit->area.x + unit->area.w / 2.0);

  if (wider)
    {
      startx -= 4;
      endx += 4;
    }
  for (int i = startx; i < endx; ++i)
    if (ingame_get_pixel(ing, i, unit->area.y + 1) != AIR)
      {
	if (ingame_get_pixel(ing, i, unit->area.y + 1) == FIRE)
	  ingame_get_hurt(ing, unit, 0.01);
	return (true);
      }
  return (false);
}

