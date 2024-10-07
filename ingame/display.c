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
  bunny_clear(&ingame->whitescreen->buffer, BLACK);

  if (ingame->fire)
    {
      t_bunny_area	cam = {
	ingame->camera.x - ingame->camera.w,
	ingame->camera.y - ingame->camera.h,
	3 * ingame->program->screen->buffer.width,
	3 * ingame->program->screen->buffer.height
      };
      int		startx = cam.x;
      int		starty = cam.y;
      int		endx = cam.w + startx;
      int		endy = cam.h + starty;

      if (startx < 0)
	startx = 0;
      if (starty < 0)
	starty = 0;
      if (endx > ingame->map_size.x)
	endx = ingame->map_size.x;
      if (endy > ingame->map_size.y)
	endy = ingame->map_size.y;

      fire(ingame->fire, false, &cam);
      for (int j = starty; j < endy; ++j)
	for (int i = startx; i < endx; ++i)
	  if (ingame->physic_map[i + j * ingame->map_size.x] == FIRE)
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
      ingame->color_map->clipable.clip_width = ingame->program->screen->buffer.width;
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
      ingame->color_map->clipable.clip_height = ingame->program->screen->buffer.height;
    }

  if (ingame->background)
    {
      ingame->background->position.x = -ingame->camera.x / 2;
      ingame->background->position.y = -ingame->camera.y / 2;
      bunny_blit(&ingame->program->screen->buffer, ingame->background, NULL);
    }
  if (ingame->remain_map)
    {
      bunny_clipable_copy(ingame->remain_map, &ingame->color_map->clipable);
      bunny_blit(&ingame->program->screen->buffer, ingame->remain_map, NULL);
    }
  bunny_blit(&ingame->program->screen->buffer, &ingame->color_map->clipable, NULL);

  for (size_t i = 0; i < ingame->last_unit && i < NBRCELL(ingame->units); i++)
    {
      t_unit		*unit = &ingame->units[i];
      t_bunny_position	pos = {
	unit->area.x - ingame->camera.x,
	unit->area.y - ingame->camera.y
      };

      if (unit->light_radius > 0)
	{
	  t_bunny_size	siz = {(int)unit->light_radius, (int)unit->light_radius};
	  t_bunny_position lpos = {pos.x, pos.y};
	  size_t	i;

	  lpos.y -= unit->area.h  / 2;
	  for (i = 0; i < 5; ++i)
	    {
	      bunny_set_disk(&ingame->whitescreen->buffer, lpos, siz, unit->light_color, 0, 0);
	      siz.x *= 0.9;
	      siz.y *= 0.9;
	    }
	}
      
      unit->sprite->clipable.position.x = pos.x;
      unit->sprite->clipable.position.y = pos.y;

      bunny_blit(&ingame->program->screen->buffer, &unit->sprite->clipable, NULL);
      
      t_bunny_accurate_area area = {
	unit->area.x - unit->area.w / 2 - ingame->camera.x,
	unit->area.y - unit->area.h - ingame->camera.y,
	unit->area.w,
	unit->area.h
      };

      if (unit->selected)
	draw_rect(ingame, &area);

      unsigned int black[3] = {BLACK, BLACK, BLACK};
      unsigned int heal[2] = {RED, BLUE};
      t_bunny_position line[3] = {
	{area.x - unit->area.w / 2, area.y - unit->area.h - 5},
	{area.x, area.y - unit->area.h - 5},
	{area.x + unit->area.w / 2, area.y - unit->area.h - 5}
      };
      if (unit != ingame->player && unit->health < 1.0)
	{
	  for (int i = 0; i < 6; ++i)
	    {
	      bunny_set_line(&ingame->program->screen->buffer, &line[0], &black[0]);
	      bunny_set_line(&ingame->program->screen->buffer, &line[1], &black[1]);
	      line[0].y += 1;
	      line[1].y += 1;
	      line[2].y += 1;
	    }

	  line[0].y -= 4;
	  line[1].y -= 4;
	  line[1].x = unit->health * (line[2].x - line[0].x) + line[0].x;
	  bunny_set_line(&ingame->program->screen->buffer, &line[0], &heal[0]);
	  line[0].y += 1;
	  line[1].y += 1;
	  bunny_set_line(&ingame->program->screen->buffer, &line[0], &heal[0]);
	}
    }

  if (ingame->fire)
    {
      bunny_clipable_copy(&ingame->fire->clipable, &ingame->color_map->clipable);
      bunny_blit(&ingame->program->screen->buffer, &ingame->fire->clipable, NULL);
    }

  if (ingame->foreground)
    bunny_blit(&ingame->program->screen->buffer, ingame->foreground, NULL);

  check_particule(ingame);

  if (ingame->program->no_light == false)
    {
      bunny_set_multiply_blit(true);
      bunny_blit(&ingame->program->screen->buffer, ingame->whitescreen, NULL);
      bunny_set_multiply_blit(false);
    }

  /////////////// MID GUI ////////////////
  bunny_clear(&ingame->action_screen->clipable.buffer, 0);
  for (int j = 0; j < ingame->program->screen->buffer.height; ++j)
    for (int i = 0; i < ingame->program->screen->buffer.width; ++i)
      {
	int jj = j + ingame->camera.y;
	int ii = i + ingame->camera.x;

	if (jj < 0 || ii < 0 || jj >= ingame->map_size.y || ii >= ingame->map_size.x)
	  continue ;	
	bool att = BITGET(ingame->attack_map, ii, jj, ingame->map_size.x);
	bool bld = BITGET(ingame->build_map, ii, jj, ingame->map_size.x);

	((unsigned int*)ingame->action_screen->pixels)[i + j * ingame->action_screen->clipable.buffer.width] = 0;
	if (att)
	  ((unsigned int*)ingame->action_screen->pixels)[i + j * ingame->action_screen->clipable.buffer.width] |= TO_RED(128) | TO_ALPHA(128);
	if (bld)
	  ((unsigned int*)ingame->action_screen->pixels)[i + j * ingame->action_screen->clipable.buffer.width] |= TO_BLUE(128) | TO_ALPHA(128);
      }
  bunny_blit(&ingame->program->screen->buffer, &ingame->action_screen->clipable, NULL);
  
  ///////////////// GUI /////////////////
  ingame_display_health_bar(ingame);
  ingame_display_selection(ingame);
  ingame_display_life(ingame);
  ingame_display_mouse(ingame);

  t_bunny_size bsiz = {ingame->brush_size, ingame->brush_size};
  t_bunny_size lbsiz = {ingame->brush_size - 3, ingame->brush_size - 3};
  unsigned int bcol = ALPHA(64, WHITE);
  unsigned int ocol = ALPHA(128, WHITE);
  t_bunny_position bpos = {
    ingame->program->screen->buffer.width - 20,
    ingame->program->screen->buffer.height - 20
  };

  bunny_set_disk(&ingame->program->screen->buffer, bpos, bsiz, bcol, 0, 3);
  bunny_set_disk(&ingame->program->screen->buffer, bpos, lbsiz, 0, ocol, 3);
  
  //// MOUVEMENT DE L'ECRAN
  if (ingame->program->screen->color_mask.argb[BLUE_CMP] < 255)
    ingame->program->screen->color_mask.argb[BLUE_CMP] += 1;
  if (ingame->program->screen->color_mask.argb[GREEN_CMP] < 255)
    ingame->program->screen->color_mask.argb[GREEN_CMP] += 1;

  if (fabs(ingame->player->health - ingame->health) > 0.01)
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


