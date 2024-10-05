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
  
  bunny_clear(&ingame->program->screen->buffer, BLACK);

  ingame_display_selection(ingame);

  ////// BARRE DE VIE
  pos.y = 0;
  bunny_clear(&ingame->health_renderer->clipable.buffer, 0);
  for (pos.x = 0; pos.x < ingame->health_renderer->clipable.buffer.width; pos.x += ingame->health_bar->clipable.clip_width)
    bunny_blit(&ingame->health_renderer->clipable.buffer, &ingame->health_bar->clipable, &pos);
  ingame->health_renderer->clipable.clip_width = ingame->health * ingame->health_renderer->clipable.buffer.width;
  bunny_blit(&ingame->program->screen->buffer, &ingame->health_renderer->clipable, NULL);
  bunny_blit(&ingame->program->screen->buffer, &ingame->health_track->clipable, NULL);

  /// VIES
  pos.x = ingame->skull->clipable.position.x;
  pos.y = ingame->skull->clipable.position.y;
  for (int i = 0; i < ingame->life; ++i)
    {
      bunny_blit(&ingame->program->screen->buffer, &ingame->skull->clipable, &pos);
      pos.x += ingame->skull->clipable.clip_width / 2;
    }

  //// CURSEUR DE SOURIS
  pos = ingame_get_real_mouse_position(ingame);
  bunny_blit(&ingame->program->screen->buffer, &ingame->cursor->clipable, &pos);

  //// MOUVEMENT DE L'ECRAN
  if (fabs(ingame->health_target - ingame->health) > 0.01)
    {
      // Hurt my feeling
      bunny_clear(&ingame->program->window->buffer, RED);
      // Shake that screen
      ingame->program->screen->rotation = (rand() % 4000 / 1000.0) - 2;
    }
  else
    {
      bunny_fill(&ingame->program->window->buffer, ALPHA(32, BLACK));
      if (fabs(ingame->program->screen->rotation *= 0.95) < 0.01)
	ingame->program->screen->rotation = 0;
    }
  bunny_blit(&ingame->program->window->buffer, ingame->program->screen, NULL);
  bunny_display(ingame->program->window);
  return (GO_ON);
}

