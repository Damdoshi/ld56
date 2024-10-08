
#include		"program.h"

// 2 * M_PI / 90 ~= 0.069

void			ingame_attack_map(t_ingame		*ing,
					  t_unit		*unit,
					  unsigned int		rad)
{
  double		shortest_value;
  double		dist;
  int			sx;
  int			sy;

  shortest_value = 2 * rad;
  for (double i = 0; i < 2 * M_PI; i += (0.1 + (rand() % 20) / 1000.0))
    for (dist = 0; dist < rad; dist += 3 + rand() % 7)
      {
	int		x = unit->area.x + cos(i) * dist;
	int		y = unit->area.y + sin(i) * dist;
	
	if (BITGET(ing->attack_map, x, y, ing->map_size.x))
	  {
	    if (shortest_value > rad)
	      {
		sx = x;
		sy = y;
	      }

	    // BITCLR(ing->attack_map, x, y, ing->map_size.x);
	  }
      }
  if (shortest_value < 2 * rad)
    {
      unit->target.x = sx;
      unit->target.y = sy;
    }
}

