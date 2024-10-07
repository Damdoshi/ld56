
#include		"program.h"

void			ingame_player_action(t_ingame	*ingame,
					     t_unit	*unit)
{
  const bool		*keys = bunny_get_keyboard();
  int			x = 0;

  if (bunny_sprite_animation_name("Crashing") == bunny_sprite_get_animation(unit->sprite))
    {
      if (bunny_sprite_is_still(unit->sprite))
	bunny_sprite_set_animation_name(unit->sprite, "GettingUp");
      return ;
    }
  if (bunny_sprite_animation_name("GettingUp") == bunny_sprite_get_animation(unit->sprite))
    return ;
  
  if (keys[BKS_Q] || keys[BKS_A] || keys[BKS_LEFT])
    x = -1;
  if (keys[BKS_D] || keys[BKS_RIGHT])
    x += 1;
  if (keys[BKS_LSHIFT] || keys[BKS_RSHIFT])
    x *= 2;
  if (x)
    ingame_go(ingame, unit, x);

  if (ingame_bottom_collision(ingame, unit))
    {
      if (x || fabs(unit->inertia.x) > 0.1)
	bunny_sprite_set_animation_name(unit->sprite, "Walking");
      else
	bunny_sprite_set_animation_name(unit->sprite, "Idle");	
    }
  else
    {
      if (unit->inertia.y < 0)
	bunny_sprite_set_animation_name(unit->sprite, "Jumping");
      else if (unit->inertia.y > 4)
	bunny_sprite_set_animation_name(unit->sprite, "Landing");
    }
}
