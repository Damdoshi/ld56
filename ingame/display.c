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
  fire(ingame->fire, true);
  bunny_clear(&ingame->program->screen->buffer, BLACK);

  set_fire_pixel(0, 0);
  // Il faut placer correctement le feu... comme les autres calques de niveau
  bunny_blit(&ingame->program->screen->buffer, &ingame->fire->clipable, NULL);


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

  
  ///////////////// GUI /////////////////
  ingame_display_health_bar(ingame);
  ingame_display_selection(ingame);
  ingame_display_life(ingame);
  ingame_display_mouse(ingame);
  
  //// MOUVEMENT DE L'ECRAN
  if (ingame->program->screen->color_mask.argb[BLUE_CMP] < 255)
    ingame->program->screen->color_mask.argb[BLUE_CMP] += 1;
  if (ingame->program->screen->color_mask.argb[GREEN_CMP] < 255)
    ingame->program->screen->color_mask.argb[GREEN_CMP] += 1;

  if (fabs(ingame->health_target - ingame->health) > 0.01)
    {
      bunny_clear(&ingame->program->window->buffer, RED);
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


