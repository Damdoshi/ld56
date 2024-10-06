
#include		"program.h"

void			ingame_jump(t_ingame		*ing,
				    t_unit		*unit)
{
  if (ingame_bottom_collision(ing, unit))
    unit->inertia.y += unit->speed.y;
}

