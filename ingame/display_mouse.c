
#include		"program.h"

void			ingame_display_mouse(t_ingame		*ingame)
{
  t_bunny_position	pos;

  pos = get_real_mouse_position(ingame->program->screen);
  bunny_blit(&ingame->program->screen->buffer, &ingame->cursor->clipable, &pos);
}
