
#include		"program.h"

void			ingame_go(t_ingame		*ing,
				  t_unit		*unit,
				  int			x)
{
  double		inertia;

  (void)ing;
  inertia = 0;
  inertia = 0.25 * x;
  unit->inertia.x += inertia;
  unit->inertia.x = bunny_clamp(unit->inertia.x, -unit->speed.x, +unit->speed.x);

  if (x < 0)
    unit->sprite->clipable.scale.x = -1;
  else if (x > 0)
    unit->sprite->clipable.scale.x = +1;
}


