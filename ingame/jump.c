
#include		"program.h"

void			ingame_jump(t_ingame		*ing,
				    t_unit		*unit)
{
  if (bunny_sprite_animation_name("Crashing") == bunny_sprite_get_animation(unit->sprite))
    return ;
  if (bunny_sprite_animation_name("GettingUp") == bunny_sprite_get_animation(unit->sprite))
    return ;
  if (ingame_bottom_collision(ing, unit, true))
    {
      unit->area.y -= 1;
      unit->inertia.y += unit->speed.y;
      bunny_sound_play(&(ing->sfx[PLAYER][20])->sound);
      bunny_sound_play(&(ing->sfx[PLAYER][21 + rand()%2])->sound);
    }
}

