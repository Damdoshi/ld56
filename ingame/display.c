// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"

t_bunny_response	ingame_display(t_ingame	*ingame)
{
  t_bunny_position	pos = ingame_get_real_mouse_position(ingame);
  
  bunny_clear(&ingame->program->screen->buffer, BLACK);

  ingame_display_selection(ingame);
  bunny_blit(&ingame->program->screen->buffer, &ingame->cursor->clipable, &pos);

  bunny_clear(&ingame->program->window->buffer, BLACK);
  bunny_blit(&ingame->program->window->buffer, ingame->program->screen, NULL);
  bunny_display(ingame->program->window);
  return (GO_ON);
}

