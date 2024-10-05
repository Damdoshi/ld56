#include "butcher.h"

void pixel_delete(t_map *map,t_bunny_position pos)
{
  if (map->map_composant[pos.x * pos.y] != EAU)
    map->map_composant[pos.x * pos.y] = AIR;
}
