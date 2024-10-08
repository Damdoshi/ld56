// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

void			main_menu_leaving(t_bunny_response	response,
					t_main_menu		*main_menu)
{
  fire(NULL, false, NULL);
  bunny_sound_loop((t_bunny_sound*)main_menu->music, false);
  bunny_sound_stop((t_bunny_sound*)main_menu->music);
  bunny_delete_sound((t_bunny_sound*)main_menu->music);
  /*
  bunny_delete_clipable(main_menu->menu);
  bunny_delete_clipable(&main_menu->text_menu[0]->clipable);
  bunny_delete_clipable(&main_menu->text_menu[1]->clipable);
  */
  (void)response;
  (void)main_menu;
}
