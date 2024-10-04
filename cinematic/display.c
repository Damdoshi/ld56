// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"cinematic.h"

t_bunny_response	cinematic_display(t_cinematic	*cinematic)
{
  bunny_clear(&cinematic->cinematic->clipable.buffer, BLACK);
  bunny_draw(&cinematic->cinematic->clipable);
  bunny_blit(&cinematic->program->screen->buffer, &cinematic->cinematic->clipable, NULL);

  bunny_clear(&cinematic->program->window->buffer, BLACK);
  bunny_blit(&cinematic->program->window->buffer, cinematic->program->screen, NULL);
  bunny_display(cinematic->program->window);
  return (GO_ON);
}

