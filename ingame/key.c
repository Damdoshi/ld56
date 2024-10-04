// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"ingame.h"

double				afabs(double			x)
{
  return (x < 0 ? x : -x);
}

t_bunny_response		ingame_key(t_bunny_event_state	state,
					    t_bunny_keysym	sym,
					    t_ingame		*ingame)
{
  if (sym == BKS_LEFT)
    {
      if (state == GO_DOWN)
	{
	  bunny_sprite_set_animation_name(ingame->mmx, "StartRunning");
	  ingame->mmx->clipable.scale.x = afabs(ingame->mmx->clipable.scale.x);
	}
      else
	bunny_sprite_set_animation_name(ingame->mmx, "Idle");
    }
  if (sym == BKS_RIGHT)
    {
      if (state == GO_DOWN)
	{
	  bunny_sprite_set_animation_name(ingame->mmx, "StartRunning");
	  ingame->mmx->clipable.scale.x = fabs(ingame->mmx->clipable.scale.x);
	}
      else
	bunny_sprite_set_animation_name(ingame->mmx, "Idle");
    }
  return (GO_ON);
}
