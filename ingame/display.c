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
  bunny_clear(&ingame->program->screen->buffer, GRAY(64));
  
  if (ingame->fire)
    {
      fire(ingame->fire, false);
      for (int j = 0; j < ingame->fire->clipable.buffer.height; ++j)
	for (int i = 0; i < ingame->fire->clipable.buffer.width; ++i)
	  if (((unsigned int*)ingame->color_map->pixels)[i + j * ingame->color_map->clipable.buffer.width] == RED)
	    set_fire_pixel(i, j);
    }

  if (ingame->camera.x < 0)
    {
      ingame->color_map->clipable.position.x = -ingame->camera.x;
      ingame->color_map->clipable.clip_x_position = 0;
      ingame->color_map->clipable.clip_width = ingame->program->screen->buffer.width - ingame->camera.x;
    }
  else
    {
      ingame->color_map->clipable.position.x = 0;
      ingame->color_map->clipable.clip_x_position = ingame->camera.x;
      ingame->color_map->clipable.clip_width = ingame->program->screen->buffer.width;                  ;
    }
  
  if (ingame->camera.y < 0)
    {
      ingame->color_map->clipable.position.y = -ingame->camera.y;
      ingame->color_map->clipable.clip_y_position = 0;
      ingame->color_map->clipable.clip_height = ingame->program->screen->buffer.height - ingame->camera.y;
    }
  else
    {
      ingame->color_map->clipable.position.y = 0;
      ingame->color_map->clipable.clip_y_position = ingame->camera.y;
      ingame->color_map->clipable.clip_height = ingame->program->screen->buffer.height;                  ;
    }

  if (ingame->background)
    bunny_blit(&ingame->program->screen->buffer, ingame->background, NULL);
  if (ingame->remain_map)
    {
      bunny_clipable_copy(ingame->remain_map, &ingame->color_map->clipable);
      bunny_blit(&ingame->program->screen->buffer, ingame->remain_map, NULL);
    }
  bunny_blit(&ingame->program->screen->buffer, &ingame->color_map->clipable, NULL);

  for (size_t i = 0; i < ingame->last_unit && i < NBRCELL(ingame->units); i++)
    {
      ingame->units[i].sprite->clipable.position.x = ingame->units[i].area.x - ingame->camera.x;
      ingame->units[i].sprite->clipable.position.y = ingame->units[i].area.y - ingame->camera.y;
      bunny_blit(&ingame->program->screen->buffer, &ingame->units[i].sprite->clipable, NULL);
    }

  if (ingame->fire)
    {
      bunny_clipable_copy(&ingame->fire->clipable, &ingame->color_map->clipable);
      bunny_blit(&ingame->program->screen->buffer, &ingame->fire->clipable, NULL);
    }

  if (ingame->foreground)
    bunny_blit(&ingame->program->screen->buffer, ingame->foreground, NULL);

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


