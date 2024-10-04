// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

t_bunny_response	main_menu_connect(int			fd,
					t_bunny_event_state	state,
					t_main_menu		*main_menu)
{
  (void)fd;
  (void)state;
  (void)main_menu;
  return (GO_ON);
}

