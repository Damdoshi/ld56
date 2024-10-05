// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"credit.h"

t_bunny_response	credit_joy_button(t_bunny_event_state		state,
					   int				joyid,
					   int				button,
					   t_credit			*credit)
{
  (void)joyid;
  (void)button;
  if (state == GO_UP)
    return (GO_ON);
  credit->program->context = MAIN_MENU;
  return (SWITCH_CONTEXT);
}

