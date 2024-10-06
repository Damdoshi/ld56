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
  fire(ingame->fire, false);
  bunny_clear(&ingame->program->screen->buffer, GRAY(64));

  for (int j = 0; j < ingame->fire->clipable.buffer.height; ++j)
    for (int i = 0; i < ingame->fire->clipable.buffer.width; ++i)
      if (((unsigned int*)ingame->layer[1]->pixels)[i + j * ingame->layer[1]->clipable.buffer.width] == RED)
	set_fire_pixel(i, j);

  ingame->layer[1]->clipable.position.x = -ingame->camera.x;
  ingame->layer[1]->clipable.position.y = -ingame->camera.y;
  ingame->fire->clipable.position.x = -ingame->camera.x;
  ingame->fire->clipable.position.y = -ingame->camera.y;
  for (size_t i = 0; i < 3; i += 1)
    {
      if (!ingame->layer[i])
	continue;
      bunny_blit(&ingame->program->screen->buffer, &ingame->layer[i]->clipable, NULL);
      if (i == 1)
	{
	  ingame->player->sprite->clipable.position.x = ingame->player->area.x - ingame->camera.x;
	  ingame->player->sprite->clipable.position.y = ingame->player->area.y - ingame->camera.y;
	  bunny_blit(&ingame->program->screen->buffer, &ingame->player->sprite->clipable, NULL);
	  bunny_blit(&ingame->program->screen->buffer, &ingame->fire->clipable, NULL);
	}
    }
  check_particule(ingame);

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


