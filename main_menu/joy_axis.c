// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

t_bunny_response	main_menu_joy_axis(int				joyid,
					 t_bunny_axis			axis,
					 float				value,
					 t_main_menu			*main_menu)
{
  (void)joyid;
  (void)axis;
  (void)value;
  (void)main_menu;
  return (GO_ON);
}

