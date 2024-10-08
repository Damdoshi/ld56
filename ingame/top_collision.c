
#include		"program.h"

bool			ingame_top_collision(t_ingame	*ing,
					     t_unit	*unit)
{
  int			startx = ceil(unit->area.x - unit->area.w / 2.0);
  int			endx = floor(unit->area.x + unit->area.w / 2.0);

  for (int i = startx; i < endx; ++i)
    if (!ingame_traversable(ing, i, unit->area.y - unit->area.h - 1))
      return (true);
  return (false);
}

