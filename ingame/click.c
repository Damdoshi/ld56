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
  (void)state;
  (void)but;
  (void)ingame;
  return (GO_ON);
}

