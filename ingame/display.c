// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"

#include		<stdio.h>

t_bunny_response	ingame_display(t_ingame	*ingame)
{
  t_bunny_position	pos;
  int			i;
  
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
    bunny_clear(&ingame->program->window->buffer, ALPHA(32, WHITE));
  
  for (i = 0; i < 3; i += 1)
    {
      if (!ingame->layer[i])
	continue;
      printf("Clip position : x: %d y: %d\n", ingame->layer[i]->clipable.clip_x_position, ingame->layer[i]->clipable.clip_y_position);
      bunny_blit(&ingame->program->screen->buffer, &ingame->layer[i]->clipable, NULL);
      if (i == 1)
	{
	  ingame->player_pic->position.x = ingame->player.area.x - ingame->camera.x - ingame->layer[i]->clipable.position.x;
	  ingame->player_pic->position.y = ingame->player.area.y - ingame->camera.y - ingame->layer[i]->clipable.position.y;
	  bunny_blit(&ingame->program->screen->buffer, ingame->player_pic, NULL);
	}
     
    }
  bunny_blit(&ingame->program->window->buffer, ingame->program->screen, NULL);
  bunny_display(ingame->program->window);
  return (GO_ON);
}


