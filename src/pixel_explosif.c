#include		"program.h"

void			pixel_explosif(t_map		*map,
				       t_bunny_position	pos,
				       int64_t		r)
{
  t_bunny_position	poss;
  t_bunny_position	pose[2];

  pose[0].x = pos.x - r;
  pose[0].y = pos.y - r;
  pose[1].x = pos.x + r;
  pose[1].y = pos.y + r;
  r = r * 2;
  poss.y = pose[0].y;
  for (int64_t i = 0; r > 0 && poss.y < pose[1].y; i++)
    {
      poss.y = pose[0].y + i;
      if (poss.y >= 0)
	for (poss.x = pose[0].x; poss.x < pose[1].x; poss.x ++)
	  {
	    if (poss.x >= 0)
	      {
		if (poss.x == pose[0].x
		    || poss.x == pose[1].x - 1
		    || poss.y == pose[0].y
		    || poss.y == pose[1].y - 1)
		  pixel_neighbour_check(map, poss);
		else
		  pixel_delete(map, poss);
	      }
	  }
      r --;
    }
}
