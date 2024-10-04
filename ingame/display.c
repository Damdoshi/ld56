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
  bunny_clear(&ingame->program->screen->buffer, BLACK);
  ingame->mmx->clipable.position.x = ingame->program->screen->buffer.width / 2;
  ingame->mmx->clipable.position.y = ingame->program->screen->buffer.height / 2;
  bunny_blit(&ingame->program->screen->buffer, &ingame->mmx->clipable, NULL);

  bunny_clear(&ingame->program->window->buffer, BLACK);
  bunny_blit(&ingame->program->window->buffer, ingame->program->screen, NULL);
  bunny_display(ingame->program->window);
  return (GO_ON);
}

