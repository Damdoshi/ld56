
#include		"program.h"

void			ingame_pixel_build(t_ingame		*ing,
					   t_bunny_position	pos)
{
  ing->physic_map[pos.x + pos.y * ing->map_size.x] = EARTH;
  ((unsigned int*)ing->color_map->pixels)[pos.x + pos.y * ing->map_size.x] = GRAY((128 - 32) + rand() % 64);
  BITCLR(ing->build_map, pos.x, pos.y, ing->map_size.x);

  int last = rand() % 3 + 2;
  for (int i = 0; i < last; ++i)
    {
      double		speed = (rand() % 5000) / 1000.0 + 5;
      double		ang = (rand() % (int)(20000 * M_PI)) / 10000.0;
      
      t_bunny_accurate_position spos = {
	cos(ang) * speed,
	sin(ang) * speed
      };
      new_particule(ing, bunny_time_plus(bunny_get_delay() * 0.5), pos, spos, YELLOW, ingame_particule_spark);
    }
}


