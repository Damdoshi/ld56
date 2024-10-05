#include "butcher.h"

void pixel_neighbour_check(t_map *map,t_bunny_position pos)
{
  int N = 0; // neighbour count
  t_bunny_position Npos;
  Npos.x = pos.x;
  Npos.y = pos.y;
  /*if (game->map[pos.x * (pos.y+1)] == NULL)
    N++;
  else
    Npos.y += 1;
  if (game->map[pos.x * (pos.y-1)] == NULL)
    N++;
  else
    Npos.y -= 1;
  if (game->map[(pos.x+1) * pos.y] == NULL)
    N++;
  else
    Npos.x += 1;
  if (game->map[(pos.x-1) * pos.y] == NULL)
    N++;
  else
  npos.x -= 1;*/
  if (N == 3 && map->map_composant[pos.x * pos.y] != EAU)
    {
      t_deltimer pix;
      pix.pos.x = Npos.x;
      pix.pos.y = Npos.y;
      //      pix.timer = frames + 20;
      map->map_composant[pos.x * pos.y] = AIR;
      //butcher_add(pix,list);
    }
}
