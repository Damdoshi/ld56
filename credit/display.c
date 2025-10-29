// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"credit.h"

t_bunny_response	credit_display(t_credit	*credit)
{
  fire(credit->fire, true, NULL);
  bunny_clear(&credit->screen->clipable.buffer, 0);
  bunny_clear(&credit->font->clipable.buffer, 0);
  bunny_draw(&credit->font->clipable);
  bunny_blit(&credit->screen->clipable.buffer, &credit->font->clipable, NULL);
  for (ssize_t j = 0; j < credit->screen->clipable.buffer.height; ++j)
    for (ssize_t i = 0; i < credit->screen->clipable.buffer.width; ++i)
      if (((unsigned int*)credit->screen->pixels)[i + j * credit->screen->clipable.buffer.width])
	set_fire_pixel(i, j);

  // bunny_fill(&credit->program->screen->buffer, ALPHA(32, BLACK));
  bunny_blit(&credit->program->screen->buffer, &credit->fire->clipable, NULL);
  bunny_blit(&credit->program->screen->buffer, &credit->font->clipable, NULL);
  bunny_blit(&credit->program->window[0]->buffer, credit->program->screen, NULL);
  bunny_display(credit->program->window[0]);
  return (GO_ON);
}

