
#include		"program.h"

void			ingame_get_hurt(t_ingame		*ing,
					double			damage)
{
  ing->health_target -= damage;
  ing->program->screen->color_mask.full = COLOR(255, 255, 128, 128);
  if (ing->health_target <= 0)
    bunny_sound_play(&(ing->sfx[PLAYER][3]->sound));
  else if (damage > 0.5)
    bunny_sound_play(&(ing->sfx[PLAYER][2]->sound));
  else if(damage > 0.15)
    bunny_sound_play(&(ing->sfx[PLAYER][1]->sound));
  else if(damage > 0.50)
    bunny_sound_play(&(ing->sfx[PLAYER][0]->sound));
}
