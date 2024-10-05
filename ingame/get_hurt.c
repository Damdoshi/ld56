
#include		"program.h"

void			ingame_get_hurt(t_ingame		*ing,
					double			damage)
{
  ing->health_target -= damage;
  ing->program->screen->color_mask.full = COLOR(255, 255, 128, 128);
  // bunny_sound_play(ing->scream);
}
