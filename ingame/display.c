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
  t_bunny_position	pos;
  
  bunny_clear(&ingame->program->screen->buffer, GREEN);

  ingame_display_selection(ingame);

  pos.x = 0;
  bunny_clear(&ingame->health_renderer->buffer, 0);
  bunny_blit(&ingame->health_renderer->buffer, &ingame->health_bar->clipable, NULL);
  

  pos = ingame_get_real_mouse_position(ingame);
  bunny_blit(&ingame->program->screen->buffer, &ingame->cursor->clipable, &pos);

  if (bunny_time_alive(ingame->end_damage))
    {
      // Hurt my feeling
      bunny_clear(&ingame->program->window->buffer, RED);
      // Shake that screen
      ingame->program->screen->rotation = (rand() % 2000 / 1000.0) - 1;
    }
  else
    bunny_clear(&ingame->program->window->buffer, ALPHA(32, BLACK));
  bunny_blit(&ingame->program->window->buffer, ingame->program->screen, NULL);
  bunny_display(ingame->program->window);
  return (GO_ON);
}

