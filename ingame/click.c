// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"ingame.h"

t_bunny_response		ingame_click(t_bunny_event_state	state,
					      t_bunny_mouse_button	but,
					      t_ingame			*ingame)
{
  if (but != BMB_LEFT
      && but != BMB_RIGHT)
    return (GO_ON);
  if (ingame->cursor_type != SELECTION)
    {
      if (state == GO_DOWN
	  && but == BMB_RIGHT)
	{
	  t_bunny_position pos = get_real_mouse_position(ingame->program->screen);

	  for (size_t i = 0; i < ingame->last_unit && i < NBRCELL(ingame->units); i++)
	    if (ingame->units[i].selected)
	      {
		ingame->units[i].target.x = pos.x + ingame->camera.x;
		ingame->units[i].target.y = pos.y + ingame->camera.y;
		ingame->units[i].target_action = ingame->cursor_type;
	      }
	}
    }
  else if (ingame->cursor_type == SELECTION)
    {
      if (but == BMB_LEFT
	  && state == GO_DOWN)
	ingame_start_select(ingame);
      else
	ingame_end_select(ingame);
    }
  return (GO_ON);
}

