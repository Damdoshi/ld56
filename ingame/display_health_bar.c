
#include		"program.h"

void			ingame_display_health_bar(t_ingame	*ingame)
{
  t_bunny_position	pos = {0, 0};

  bunny_clear(&ingame->health_renderer->clipable.buffer, 0);
  for (pos.x = 0; pos.x < ingame->health_renderer->clipable.buffer.width; pos.x += ingame->health_bar->clipable.clip_width)
    bunny_blit(&ingame->health_renderer->clipable.buffer, &ingame->health_bar->clipable, &pos);
  ingame->health_renderer->clipable.clip_width = ingame->health * ingame->health_renderer->clipable.buffer.width;
  bunny_blit(&ingame->program->screen->buffer, &ingame->health_renderer->clipable, NULL);
  bunny_blit(&ingame->program->screen->buffer, &ingame->health_track->clipable, NULL);
}
