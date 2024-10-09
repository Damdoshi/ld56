
#include	"program.h"

void		ingame_pixel_delete(t_ingame		*ing,
				    t_bunny_position	pos,
				    double		r)
{
  if (pos.x < 0 || pos.y < 0 || pos.x >= ing->map_size.x || pos.y >= ing->map_size.y)
    return ;
  int		type = ingame_get_pixel(ing, pos.x, pos.y);

  if (type != WATER)
    {
      t_bunny_position p[4] = {
	{pos.x - 1, pos.y + 0},
	{pos.x + 1, pos.y + 0},
	{pos.x - 0, pos.y - 1},
	{pos.x - 0, pos.y + 1}
      };

      BITCLR(ing->attack_map, pos.x, pos.y, ing->map_size.x);
      unsigned int lost = ((unsigned int*)ing->color_map->pixels)[pos.x + pos.y * ing->map_size.x];
      ((unsigned int*)ing->color_map->pixels)[pos.x + pos.y * ing->map_size.x] = 0;
      ing->physic_map[pos.x + pos.y * ing->map_size.x] = AIR;

      t_bunny_accurate_position spos = {
	3 * ((rand() % 1000) / 1000.0 - 0.5),
	3 * ((rand() % 1000) / 1000.0 - 0.5)
      };
      new_particule(ing, 3, pos, spos, lost, ingame_particule_debris);
      
      for (size_t i = 0; i < NBRCELL(p); ++i)
	if (ingame_is_orphan(ing, p[i].x, p[i].y))
	  ingame_add_event(ing, ing->frame_counter + 1, KILL_PIXEL, &p[i]);
    }
  if (type == EXPLODE)
    return (ingame_pixel_explosif(ing, pos, r + 0.1));
}

