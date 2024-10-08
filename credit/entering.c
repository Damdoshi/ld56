// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"credit.h"

t_bunny_response	credit_entering(t_credit		*credit)
{
  bunny_clear(&credit->program->window->buffer, BLACK);
  bunny_clear(&credit->program->screen->buffer, BLACK);
  assert((credit->screen = bunny_new_pixelarray(credit->program->screen->buffer.width, credit->program->screen->buffer.height)));
  assert((credit->font = bunny_load_text("./res/credit/font.dab")));
  assert((credit->fire = bunny_new_pixelarray(credit->program->screen->buffer.width, credit->program->screen->buffer.height)));
  bunny_clear(&credit->fire->clipable.buffer, 0);
  return (GO_ON);
}

