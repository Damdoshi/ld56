#include "butcher.h"

void butcher_add(t_deltimer pix, t_deletelist list)
{
  //list.pixels[list.len] = pix;
  list.len +=1;
}

void butcher(t_ingame *game)
{
  int64_t i = 0;
  int64_t len = 0;
  t_deletelist list;
  while (i < len )//&& i < NBRCELL)
    {
      //if (list.pixels[i].timer > frames)
	{
	  //pixel_delete(game.map,list.pixels[i].pos);
	  //memcpy(&list.pixels[i],&list.pixels[len],sizeof(list.pixels[len]));
	  len -1;
	}
      i++;
    }
}
