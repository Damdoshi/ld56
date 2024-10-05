
#include	"program.h"

void		ingame_pixel_delete(t_ingame		*ing,
				    t_bunny_position	pos)
{
  if (ingame_get_pixel(ing, pos.x, pos.y) == EXPLODE)
    return (ingame_pixel_explosif(ing, pos, 2));
  if (ingame_get_pixel(ing, pos.x, pos.y) != WATER)
    {
      t_bunny_position p[4] = {
	{pos.x - 1, pos.y + 0},
	{pos.x + 1, pos.y + 0},
	{pos.x - 0, pos.y - 1},
	{pos.x - 0, pos.y + 1}
      };

      ing->physic_map[pos.x + pos.y * ing->map_size.x] = AIR;
      for (size_t i = 0; i < NBRCELL(p); ++i)
	if (ingame_is_orphan(ing, p[i].x, p[i].y))
	  ingame_add_event(ing, ing->frame_counter + 1, KILL_PIXEL, p[i]);
    }
}

