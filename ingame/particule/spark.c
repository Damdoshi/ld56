
#include		"program.h"

bool			ingame_particule_spark(t_ingame		*ingame,
					       t_particule	*part,
					       int		idx)
{
  t_bunny_position	pos;

  pos.x = part->pos[idx].x - ingame->camera.x;
  pos.y = part->pos[idx].y - ingame->camera.y;

  part->pos[idx].x += part->spos[idx].x;
  part->pos[idx].y += part->spos[idx].y;
  
  part->spos[idx].y += 0.05;
  
  // ingame->aura->clipable.color_mask.full = part->color[idx] | BLACK;
  // bunny_blit(&ingame->program->screen->buffer, &ingame->aura->clipable, &pos);
  // bunny_blit(&ingame->program->screen->buffer, &ingame->aura->clipable, &pos);

  bunny_set_pixel(&ingame->program->screen->buffer, pos, part->color[idx]);
  return (false);
}

