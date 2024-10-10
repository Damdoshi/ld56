
#include		"program.h"

// 2 * M_PI / 90 ~= 0.069

void			ingame_move_map(t_ingame		*ing,
					t_bunny_bitfield	*bf,
					t_unit			*unit,
					unsigned int		rad)
{
  double		shortest_value;
  double		dist;

  shortest_value = 2 * rad;
  for (double i = 0; i < 2 * M_PI; i += (0.1 + (rand() % 20) / 1000.0))
    for (dist = 0; dist < rad; dist += 3 + rand() % 7)
      {
	int		x = unit->area.x + cos(i) * dist;
	int		y = unit->area.y + sin(i) * dist;

	if (x < 0)
	  x = 0;
	if (y < 0)
	  y = 0;
	if (x >= ing->map_size.x - 1)
	  x = ing->map_size.x - 1;
	if (y >= ing->map_size.y - 1)
	  y = ing->map_size.y - 1;
	
	if (BITGET(bf, x, y, ing->map_size.x))
	  {
	    if (dist < shortest_value)
	      {
		unit->target.x = x;
		unit->target.y = y;
		shortest_value = dist;
	      }
	  }
      }
}

