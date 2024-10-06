
#include		"program.h"

void			ingame_go(t_ingame		*ing,
				  t_unit		*unit,
				  int			x)
{
  double		inertia;

  (void)ing;
  inertia = 0;
  if (x < 0)
    inertia = -0.25;
  if (x > 0)
    inertia = +0.25;
  unit->inertia.x += inertia;
  unit->inertia.x = bunny_clamp(unit->inertia.x, -unit->speed.x, +unit->speed.x);
}


