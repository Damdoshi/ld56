
#include		"program.h"

void			ingame_get_hurt(t_ingame		*ing,
					t_unit			*unit,
					double			damage)
{
  unit->health -= damage;

  if (unit == ing->player) // C'est moche ca.
    ing->program->screen->color_mask.full = COLOR(255, 255, 128, 128);

  if (unit->health <= 0) // Game over
    sound_play(unit->hurt[5]);
  else if (damage > 0.5)
    sound_play(unit->hurt[4]);
  else if(damage > 0.15)
    sound_play(unit->hurt[1 + rand() % 3]);
  else if(damage > 0.05)
    sound_play(unit->hurt[0]);
}
