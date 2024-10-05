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
  if (but != BMB_LEFT)
    return (GO_ON);
  if (state == GO_DOWN)
    ingame_start_select(ingame);
  else
    ingame_end_select(ingame);
  return (GO_ON);
}

