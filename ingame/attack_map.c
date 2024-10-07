#include			"program.h"

int				kclamps(int			value,
					int			min,
					int			max)
{
  if (value < min)
    return min;
  if (value > max)
    return max;
  return value;
}

void				attack_map(t_ingame		*ing,
					   t_unit		*unit,
					   unsigned int		r)
{
  //chaque unit doit manger 1 pixel
  //dans t_unit ya nb qui permet de savoir combien ont ete manger dans le area
  for (size_t i = 0; i < ing->last_unit && i < NBRCELL(unit); i++)
    {
      int sy = ;
      int sx =  ;
      for (size_t y = pos_start.y; y < pos_end.y; y++)
	for (size_t x = pos_start.x; x < pos_end.x; x++)
	  {
	    save_pos.x = unit[ind[i]].target.x;
	    save_pos.y = unit[ind[i]].target.y;
	    if (bunny_bitfield_get(ing->attack_map, x + (y * (r*2))))
	      ;
	    //unit[i].target.x = save_pos.x;
	    //unit[i].target.y = save_pos.y;
	  }
    }
}
