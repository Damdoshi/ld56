
#include		"program.h"

void			ingame_go(t_ingame		*ing,
				  t_unit		*unit,
				  int			x)
{
  double		inertia;

  (void)ing;
  inertia = 0;
  if (x < 0)
    inertia = -0.25;
  if (x > 0)
    inertia = +0.25;
  unit->inertia.x += inertia;
  unit->inertia.x = bunny_clamp(unit->inertia.x, -unit->speed.x, +unit->speed.x);
  if (ingame_bottom_collision(ing, unit))
    bunny_sprite_set_animation_name(unit->sprite, "Walking");
  else if (unit->inertia.y < 0)
    bunny_sprite_set_animation_name(unit->sprite, "Jumping");
  else
    {
      if (unit->inertia.y >= 0)
	bunny_sprite_set_animation_name(unit->sprite, "Idle");
      else if (unit->inertia.y < 4)
	bunny_sprite_set_animation_name(unit->sprite, "Landing");
      else  if (unit->inertia.y > 0)
	bunny_sprite_set_animation_name(unit->sprite, "Falling");
    }
  unit->sprite->clipable.scale.x *= x;
}


