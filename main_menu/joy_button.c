// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

t_bunny_response	main_menu_joy_button(t_bunny_event_state		state,
					   int				joyid,
					   int				button,
					   t_main_menu			*main_menu)
{
  (void)state;
  (void)joyid;
  (void)button;
  (void)main_menu;
  return (GO_ON);
}

