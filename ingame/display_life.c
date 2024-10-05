
#include		"program.h"

void			ingame_display_life(t_ingame		*ingame)
{
  t_bunny_position	pos;
  
  pos.x = ingame->skull->clipable.position.x;
  pos.y = ingame->skull->clipable.position.y;
  for (int i = 0; i < ingame->life; ++i)
    {
      bunny_blit(&ingame->program->screen->buffer, &ingame->skull->clipable, &pos);
      pos.x += ingame->skull->clipable.clip_width / 2;
    }
}
