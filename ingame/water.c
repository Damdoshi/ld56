
#include		"program.h"

void			ingame_water(t_ingame	*ing)
{
  static int		wlimit = 0;
  static int		shaker = 0;
  int			starty = ing->camera.y - ing->program->screen->buffer.height;
  int			startx = ing->camera.x - ing->program->screen->buffer.width;
  int			endy;
  int			endx;
  int			rnd;

  if (startx < 1)
    startx = 1;
  if ((endx = startx + ing->program->screen->buffer.width * 3) > ing->map_size.x - 1)
    endx = ing->map_size.x - 1;
  if (starty < 1)
    starty = 0;
  if ((endy = starty + ing->program->screen->buffer.height * 3) > ing->map_size.y - 1)
    endy = ing->map_size.y - 1;

  rnd = (shaker + 1) % 2 ? +1 : -1; 
  if (rnd < 0) 
    { 
      int tmp = startx; 
      
      startx = endx; 
      endx = tmp; 
    }

  wlimit += 1;
    
  t_bunny_bitfield	*peek;
  t_bunny_bitfield	*poke;

  peek = ing->water_map[ing->current_water_map];
  poke = ing->water_map[(ing->current_water_map + 1) % 2];

  // On nettoie poke - PAS TOUT, car sinon on risque d'effacer l'eau hors champ
  for (int j = starty; j != endy; j += 1)
    for (int i = startx; i != endx; i += rnd)
      BITCLR(poke, i, j, ing->map_size.x);

  for (int j = starty; j != endy; j += 1)
    {      
      for (int i = startx; i != endx; i += rnd)
	{
	  bool current = BITGET(peek, i, j, ing->map_size.x);
	  int current_type = ingame_get_pixel(ing, i, j);

	  if (current_type == WATER_SOURCE)
	    {
	      if (wlimit % 2 == 0)
		BITSET(poke, i, j, ing->map_size.x);
	    }
	  if (current_type == WATER_DEATH)
	    {
	      BITCLR(peek, i, j, ing->map_size.x);
	      BITCLR(poke, i, j, ing->map_size.x);
	      continue ;
	    }
	  if (!current)
	    continue ;

	  bool bottom = BITGET(peek, i, j + 1, ing->map_size.x);
	  int bottom_type = ingame_get_pixel(ing, i, j + 1);
	  int pokoc = BITGET(poke, i, j + 1, ing->map_size.x);

	  int wleft = BITGET(peek, i - 1, j, ing->map_size.x);
	  int wright = BITGET(peek, i + 1, j, ing->map_size.x);
	  int left = ingame_get_pixel(ing, i - 1, j);
	  int right = ingame_get_pixel(ing, i + 1, j);
	  int pokl = BITGET(poke, i - 1, j, ing->map_size.x);
	  int pokr = BITGET(poke, i + 1, j, ing->map_size.x);

	  int nolwater = !wleft && !pokl;
	  int norwater = !wright && !pokr;
	  
	  int leftempty = (left == AIR || left == FIRE) && nolwater;
	  int rightempty = (right == AIR || right == FIRE) && norwater;

	  if (bottom == false && pokoc == false
	      && (bottom_type == AIR || bottom_type == FIRE || bottom_type == WATER_DEATH))
	    {
	      if (nolwater && !norwater && rand() % 2)
		{
		  BITSET(poke, i - 1, j, ing->map_size.x);
		  if (left == FIRE)
		    ingame_set_pixel(ing, i - 1, j, AIR);
		  BITCLR(peek, i, j, ing->map_size.x);
		}
	      else if (!nolwater && norwater && rand() % 2)
		{
		  BITSET(poke, i + 1, j, ing->map_size.x);
		  if (right == FIRE)
		    ingame_set_pixel(ing, i + 1, j, AIR);
		  BITCLR(peek, i, j, ing->map_size.x);
		}
	      else
		{
		  BITSET(poke, i, j + 1, ing->map_size.x);
		  if (bottom_type == FIRE)
		    ingame_set_pixel(ing, i, j + 1, AIR);
		  BITCLR(peek, i, j, ing->map_size.x);
		}
	    }
	  else
	    {
	      if (leftempty && rightempty)
		{
		  int lr = i + (rand() % 2 ? +1 : -1);
		  
		  BITSET(poke, lr, j, ing->map_size.x);
		  ingame_set_pixel(ing, lr, j, AIR);
		  BITCLR(peek, i, j, ing->map_size.x);
		}
	      else if (leftempty && !rightempty)
		{
		  BITSET(poke, i - 1, j, ing->map_size.x);
		  if (left == FIRE)
		    ingame_set_pixel(ing, i - 1, j, AIR);
		  BITCLR(peek, i, j, ing->map_size.x);
		}
	      else if (!leftempty && rightempty)
		{
		  BITSET(poke, i + 1, j, ing->map_size.x);
		  if (right == FIRE)
		    ingame_set_pixel(ing, i + 1, j, AIR);
		  BITCLR(peek, i, j, ing->map_size.x);
		}
	      else
		{
		  BITSET(poke, i, j, ing->map_size.x);
		  if (current_type == FIRE) // AU cas ou...
		    ingame_set_pixel(ing, i, j, AIR);
		}
	    }
	}
    }

  ing->current_water_map = (ing->current_water_map + 1) % 2;
}
