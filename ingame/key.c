// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"

t_bunny_response		ingame_key(t_bunny_event_state	state,
					    t_bunny_keysym	sym,
					    t_ingame		*ingame)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_1 || sym == BKS_NUMPAD1)
    {
      ingame->cursor_type = SELECTION;
      bunny_sprite_set_animation_name(ingame->cursor, "Selection");
      return (GO_ON);
    }
  if (sym == BKS_2 || sym == BKS_NUMPAD2)
    {
      ingame->cursor_type = ATTACK;
      bunny_sprite_set_animation_name(ingame->cursor, "Attack");
      return (GO_ON);
    }
  if (sym == BKS_3 || sym == BKS_NUMPAD3)
    {
      ingame->cursor_type = CONSTRUCTION;
      bunny_sprite_set_animation_name(ingame->cursor, "Construction");
      return (GO_ON);
    }

  if (sym == BKS_ADD)
    if ((ingame->brush_size += 1) > 15)
      ingame->brush_size = 15;

  if (sym == BKS_SUBTRACT)
    if ((ingame->brush_size -= 1) < 5)
      ingame->brush_size = 5;
  
  if (sym == BKS_Z || sym == BKS_W || sym == BKS_SPACE || sym == BKS_UP)
    ingame_jump(ingame, ingame->player);

  if (sym >= BKS_F1 && sym <= BKS_F4)
    {
      ingame_get_hurt(ingame, ingame->player, 0.1 * (sym - BKS_F1 + 1));
      return (GO_ON);
    }
  return (GO_ON);
}
