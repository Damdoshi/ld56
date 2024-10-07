// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

t_bunny_response	main_menu_entering(t_main_menu		*main_menu)
{
  assert((main_menu->menu = bunny_load_picture("res/main_menu/background.dab")));
  assert((main_menu->cursor = bunny_load_sprite("res/main_menu/cursor.dab")));
  assert((main_menu->text_menu[0] = bunny_load_text("res/main_menu/start.dab")));
  assert((main_menu->text_menu[1] = bunny_load_text("res/main_menu/exit.dab")));
  assert((main_menu->music = bunny_load_music("res/main_menu/menu.ogg")));
  assert((main_menu->click = bunny_load_effect("res/main_menu/sfx/click.ogg")));
  bunny_clear(&main_menu->program->window->buffer, BLACK);
  t_bunny_sound *son = (t_bunny_sound*)(main_menu->music);

  bunny_sound_loop(son, true);
  bunny_sound_play(son);
  return (GO_ON);
}

