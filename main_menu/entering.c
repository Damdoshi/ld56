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
  if ((main_menu->menu = bunny_load_picture("res/main_menu/background.dab")) == NULL)
    return (EXIT_ON_ERROR);
  if ((main_menu->cursor = bunny_load_sprite("res/main_menu/cursor.dab")) == NULL)
    return (EXIT_ON_ERROR);
  if ((main_menu->text_menu[0] = bunny_load_text("res/main_menu/start.dab")) == NULL)
    return (EXIT_ON_ERROR);
  if ((main_menu->text_menu[1] = bunny_load_text("res/main_menu/exit.dab")) == NULL)
    return (EXIT_ON_ERROR);
  if ((main_menu->music = bunny_load_music("res/main_menu/menu.ogg")) == NULL)
    return (EXIT_ON_ERROR);
  bunny_clear(&main_menu->program->window->buffer, BLACK);
  t_bunny_sound *son = (t_bunny_sound*)(main_menu->music);
  bunny_sound_play(son);
  bunny_sound_loop(son, true);
  // bunny_set_mouse_visibility(main_menu->program->window, true);

  /*
  main_menu->pos_txt[0].x = (main_menu->program->screen->buffer.width / 2) - (main_menu->text_menu[0]->clipable.buffer.width / 2);
  main_menu->pos_txt[0].y = (main_menu->program->screen->buffer.height / 2 - main_menu->text_menu[0]->clipable.buffer.height / 2) - 30;
  main_menu->pos_txt[0].w = main_menu->text_menu[0]->clipable.buffer.width;
  main_menu->pos_txt[0].h = main_menu->text_menu[0]->clipable.buffer.height;

  main_menu->pos_txt[0].x = main_menu->program->screen->buffer.width / 2 - main_menu->text_menu[0]->clipable.buffer.width / 2;
  main_menu->pos_txt[0].y = main_menu->program->screen->buffer.height / 2 - main_menu->text_menu[0]->clipable.buffer.height / 2;
  main_menu->pos_txt[0].w = main_menu->text_menu[0]->clipable.buffer.width;
  main_menu->pos_txt[0].h = main_menu->text_menu[0]->clipable.buffer.height;
  */

  (void)main_menu;
  return (GO_ON);
}

