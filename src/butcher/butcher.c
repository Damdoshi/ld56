#include "butcher.h"

void butcher_add(t_deltimer pix, t_deletelist list)
{
  list.pixels[list.len] = pix;
  list.len +=1;
}

void butcher(game game)
{
  while (i < len && i < NBRCELL)
    {
      if (list.pixels[i].timer > frames)
	{
	  pixel_delete(game.map,list.pixels[i].pos);
	  memcpy(&list.pixels[i],&list.pixels[len],sizeof(list.pixels[len]));
	  len -1;
	}
      i++;
    }
}
