
#include		"program.h"

// 2 * M_PI / 90 ~= 0.069

void			ingame_build_map(t_ingame		*ing,
					 t_unit			*unit,
					 unsigned int		rad)
{
  double		dist;

  for (double i = 0; i < 2 * M_PI; i += (0.050 + (rand() % 20) / 1000.0))
    for (dist = 0; dist < rad; dist += 3 + rand() % 7)
      {
	int		x = unit->area.x + cos(i) * dist;
	int		y = unit->area.y + sin(i) * dist;
	
	if (BITGET(ing->build_map, x, y, ing->map_size.x))
	  {
	    unit->target.x = x;
	    unit->target.y = y;
	    // BITCLR(ing->attack_map, x, y, ing->map_size.x);
	  }
      }
}

