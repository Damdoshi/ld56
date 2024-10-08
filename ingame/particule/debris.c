
#include		"program.h"

bool			ingame_particule_debris(t_ingame	*ingame,
						t_particule	*part,
						int		idx)
{
  t_bunny_position	pos;

  pos.x = part->pos[idx].x - ingame->camera.x;
  pos.y = part->pos[idx].y - ingame->camera.y;
  
  part->pos[idx].x += part->spos[idx].x;
  part->pos[idx].y += part->spos[idx].y;

  for (size_t j = 0; j < 3; ++j)
    {
      bunny_set_pixel(&ingame->program->screen->buffer, pos, part->color[idx]);
      pos.x += rand() % 3 - 1;
      pos.y += rand() % 3 - 1;
    }

  part->spos[idx].y += 0.05;
  return (false);
}
