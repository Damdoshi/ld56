#include		"program.h"

void			ingame_pixel_explosif(t_ingame		*ing,
					      t_bunny_position	pos,
					      double		r)
{
  t_bunny_position	start;
  t_bunny_position	end;

  if (r > 15)
    r = 15;
  if (!bunny_sound_is_playing(&(ing->sfx[AMBIENT][4]->sound)))
    bunny_sound_play(&(ing->sfx[AMBIENT][4]->sound));
  if ((start.x = pos.x - r) < 0)
    start.x = 0;
  if ((start.y = pos.y - r) < 0)
    start.y = 0;

  if ((end.x = pos.x + r) > ing->map_size.x)
    end.x = ing->map_size.x;
  if ((end.y = pos.y + r) > ing->map_size.y)
    end.y = ing->map_size.y;

  for (pos.y = start.y; pos.y < end.y; ++pos.y)
    for (pos.x = start.x; pos.x < end.x; pos.x ++)
      ingame_pixel_delete(ing, pos, r);
}
