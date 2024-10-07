
#include		"program.h"

void			ingame_pixel_build(t_ingame		*ing,
					   t_bunny_position	pos)
{
  ing->physic_map[pos.x + pos.y * ing->map_size.x] = EARTH;
  ((unsigned int*)ing->color_map->pixels)[pos.x + pos.y * ing->map_size.x] = GRAY((128 - 32) + rand() % 64);
  BITCLR(ing->build_map, pos.x, pos.y, ing->map_size.x);
}

