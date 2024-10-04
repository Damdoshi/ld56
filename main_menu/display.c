// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

t_bunny_response	main_menu_display(t_main_menu	*main_menu)
{
  ///
  bunny_blit(&main_menu->program->window->buffer, main_menu->program->screen, NULL);
  bunny_display(main_menu->program->window);
  return (GO_ON);
}

