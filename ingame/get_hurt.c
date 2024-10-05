
#include		"program.h"

void			ingame_get_hurt(t_ingame		*ing,
					double			damage)
{
  ing->end_damage = bunny_time_plus(damage);
  ing->health_target -= damage;
  // bunny_sound_play(ing->scream);
}
