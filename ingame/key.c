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
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_1)
    {
      ingame->cursor_type = SELECTION;
      bunny_sprite_set_animation_name(ingame->cursor, "Selection");
      return (GO_ON);
    }
  if (sym == BKS_2)
    {
      ingame->cursor_type = ATTACK;
      bunny_sprite_set_animation_name(ingame->cursor, "Attack");
      return (GO_ON);
    }
  if (sym == BKS_3)
    {
      ingame->cursor_type = CONSTRUCTION;
      bunny_sprite_set_animation_name(ingame->cursor, "Construction");
      return (GO_ON);
    }


  if (sym == BKS_F1)
    {
      ingame_get_hurt(ingame, 0.1);
      return (GO_ON);
    }


  /*
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
  */
  return (GO_ON);
}
