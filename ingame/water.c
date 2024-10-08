
#include		"program.h"

void			ingame_water(t_ingame	*ing)
{
  int			starty = ing->camera.y - ing->program->screen->buffer.height;
  int			endy;

  if (starty < 1)
    starty = 0;
  if ((endy = starty + ing->program->screen->buffer.height * 3) > ing->map_size.y - 1)
    endy = ing->map_size.y - 1;
  
  t_bunny_bitfield	*peek;
  t_bunny_bitfield	*poke;

  peek = ing->water_map[ing->current_water_map];
  poke = ing->water_map[(ing->current_water_map + 1) % 2];
  for (int j = starty; j < endy; ++j)
    {
      int		startx = ing->camera.x - ing->program->screen->buffer.width;
      int		endx;

      if (startx < 1)
	startx = 1;
      if ((endx = startx + ing->program->screen->buffer.width * 3) > ing->map_size.x - 1)
	endx = ing->map_size.x - 1;
      
      for (int i = startx; i < endx; ++i)
	{
	  bool current = BITGET(peek, i, j, ing->map_size.x);
	  int current_type = ingame_get_pixel(ing, i, j);

	  if (current_type == WATER_SOURCE)
	    {
	      BITSET(peek, i, j, ing->map_size.x);
	      BITSET(poke, i, j, ing->map_size.x);
	      current = true;
	    }
	  
	  if (!current)
	    continue ;
	  bool bottom = BITGET(peek, i, j + 1, ing->map_size.x);
	  int bottom_type = ingame_get_pixel(ing, i, j + 1);

	  if (bottom == false && (bottom_type == AIR || bottom_type == FIRE))
	    BITSET(poke, i, j + 1, ing->map_size.x);
	  else
	    {
	      int wleft = BITGET(peek, i - 1, j, ing->map_size.x);
	      int wright = BITGET(peek, i + 1, j, ing->map_size.x);
	      int left = ingame_get_pixel(ing, i - 1, j);
	      int right = ingame_get_pixel(ing, i + 1, j);
	      
	      int leftempty = (left == AIR || left == FIRE) && wleft == false;
	      int rightempty = (right == AIR || right == FIRE) && wright == false;

	      if (leftempty && rightempty)
		BITSET(poke, i + (rand() % 2 ? +1 : -1), j, ing->map_size.x);
	      else if (leftempty && !rightempty)
		BITSET(poke, i - 1, j, ing->map_size.x);
	      else if (!leftempty && rightempty)
		BITSET(poke, i + 1, j, ing->map_size.x);
	      else
		{
		  BITSET(poke, i, j, ing->map_size.x);
		  continue ;
		}
	    }
	  BITCLR(peek, i, j, ing->map_size.x);
	}
    }

  ing->current_water_map = (ing->current_water_map + 1) % 2;
}
