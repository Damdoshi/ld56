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
  bunny_clear(&main_menu->text_menu[0]->clipable.buffer, 0);
  bunny_draw(&main_menu->text_menu[0]->clipable);
  bunny_blit(&main_menu->menu->buffer, &main_menu->text_menu[0]->clipable, NULL);

  bunny_clear(&main_menu->text_menu[1]->clipable.buffer, 0);
  bunny_draw(&main_menu->text_menu[1]->clipable);
  bunny_blit(&main_menu->menu->buffer, &main_menu->text_menu[1]->clipable, NULL);

  bunny_blit(&main_menu->program->screen->buffer, main_menu->menu, NULL);

  t_bunny_position	pos = get_real_mouse_position(main_menu->program->screen);

  main_menu->cursor->clipable.position.x = pos.x;
  main_menu->cursor->clipable.position.y = pos.y;
  bunny_blit(&main_menu->program->screen->buffer, &main_menu->cursor->clipable, NULL);

  bunny_blit(&main_menu->program->window->buffer, main_menu->program->screen, NULL);
  bunny_display(main_menu->program->window);
  return (GO_ON);
}

