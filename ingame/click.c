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
  if (but != BMB_LEFT && but != BMB_RIGHT)
    return (GO_ON);

  if (ingame->cursor_type == SELECTION)
    {
      if (but == BMB_LEFT)
	{
	  if (state == GO_DOWN)
	    ingame_start_select(ingame);
	  else
	    ingame_end_select(ingame);
	}
      else if (but == BMB_RIGHT && state == GO_DOWN)
	{
	  t_bunny_position pos = get_real_mouse_position(ingame->program->screen);
	  int wu = (ingame->last_selection - 1);
	  int xdiff = (-wu / 2) * 8;
	  int moved = 0;

	  pos.x += ingame->camera.x;
	  pos.y += ingame->camera.y;
	  for (size_t i = 0; i < ingame->last_selection && i < NBRCELL(ingame->selection); i++)
	    {
	      ingame->selection[i]->target.x = pos.x + xdiff + moved * 8;
	      ingame->selection[i]->target.y = pos.y;
	      ingame->selection[i]->target_action = ingame->cursor_type;
	      moved += 1;
	    }
	}
    }
  return (GO_ON);
}

