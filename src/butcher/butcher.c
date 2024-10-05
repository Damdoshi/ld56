#include "butcher.h"

void butcher_add(t_deltimer pix, t_deletelist list)
{
  list.pixels[list.len] = pix;
  list.len +=1;
}

void butcher(t_ingame *game)
{
  while (i < len && i < NBRCELL)
    {
      if (game->list.pixels[i].timer > game->frames)
	{
	  pixel_delete(game,game->list.pixels[i].pos);
	  memcpy(&game->list.pixels[i],&game->list.pixels[len],sizeof(list.pixels[len]));
	  len -1;
	}
      i++;
    }
}
