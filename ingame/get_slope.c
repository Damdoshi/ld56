

#include		"program.h"

double			ingame_get_slope(t_ingame	*ing,
					 t_unit		*unit)
{
  int			startx = ceil(unit->area.x - 5);
  int			endx = floor(unit->area.x + 5);

  t_bunny_position	left = {startx, 0};
  t_bunny_position	right = {endx, 0};

  for (int i = 0; i < unit->area.h; ++i)
    if (ingame_get_pixel(ing, left.x, unit->area.y - i) == AIR)
      {
	left.y = unit->area.y - i;
	break ;
      }
  for (int i = 0; i < unit->area.h; ++i)
    if (ingame_get_pixel(ing, right.x, unit->area.y - i) == AIR)
      {
	right.y = unit->area.y - i;
	break ;
      }

  printf("L R Y Y - %d %d\n", left.y, right.y);
  
  double ret = atan2(left.y - right.y, left.x - right.x) + M_PI;

  return (ret * (180 / M_PI));
}
