#include		"program.h"
#include		"CONTEXT.h"

t_bunny_response	CONTEXT_display(t_CONTEXT	*CONTEXT)
{
  ///
  bunny_blit(&CONTEXT->program->window->buffer, CONTEXT->program->screen, NULL);
  bunny_display(CONTEXT->program->window);
  return (GO_ON);
}

