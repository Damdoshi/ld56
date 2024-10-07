
#include		"program.h"

void			ingame_get_hurt(t_ingame		*ing,
					t_unit			*unit,
					double			damage)
{
  unit->health -= damage;

  if (unit == ing->player) // C'est moche ca.
    ing->program->screen->color_mask.full = COLOR(255, 255, 128, 128);

  if (unit->health <= 0) // Game over
    bunny_sound_play(&unit->hurt[5]->sound);
  else if (damage > 0.5)
    bunny_sound_play(&unit->hurt[4]->sound);
  else if(damage > 0.15)
    bunny_sound_play(&unit->hurt[1 + rand() % 3]->sound);
  else if(damage > 0.05)
    bunny_sound_play(&unit->hurt[0]->sound);
}
