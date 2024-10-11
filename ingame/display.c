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
  bunny_clear(&ingame->program->screen->buffer, BLACK);
  bunny_clear(&ingame->whitescreen->buffer, BLACK);
  ingame->enlighted = false;

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
	  
	  if (unit->type != HERO)
	    {
	      siz.x *= unit->health;
	      siz.y *= unit->health;
	      if (distance(unit->area.x + unit->area.w / 2, unit->area.y,
			   ingame->player->area.x + ingame->player->area.w / 2,
			   ingame->player->area.y) < pow(siz.x * 1.2, 2))
		ingame->enlighted = true;
	    }
	  lpos.y -= unit->area.h  / 2;
	  for (i = 0; i < 5; ++i)
	    {
	      bunny_set_disk(&ingame->whitescreen->buffer, lpos, siz, unit->light_color, 0, 0);
	      siz.x *= 0.8;
	      siz.y *= 0.8;
	    }
	}
      
      unit->sprite->clipable.position.x = pos.x;
      unit->sprite->clipable.position.y = pos.y;

      if (unit->type == SPECTER)
	bunny_blit(&ingame->specter_map->buffer, &unit->sprite->clipable, NULL);
      bunny_blit(&ingame->program->screen->buffer, &unit->sprite->clipable, NULL);
      
      t_bunny_accurate_area area = {
	unit->area.x - unit->area.w / 2 - ingame->camera.x,
	unit->area.y - unit->area.h - ingame->camera.y,
	unit->area.w,
	unit->area.h
      };

      if (unit->selected)
	{
	  draw_rect(ingame, &area);
	  /*
	  t_bunny_position tline[2] = {
	    {area.x, area.y},
	    {unit->target.x - ingame->camera.x, unit->target.y - ingame->camera.y}
	  };
	  unsigned int tcol[2] = {RED, RED};

	  bunny_set_line(&ingame->program->screen->buffer, tline, tcol);
	  */
	}

      unsigned int black[3] = {BLACK, BLACK, BLACK};
      unsigned int heal[2] = {RED, BLUE};
      t_bunny_position line[3] = {
	{area.x - unit->area.w / 2, area.y - unit->area.h - 5},
	{area.x, area.y - unit->area.h - 5},
	{area.x + unit->area.w / 2, area.y - unit->area.h - 5}
      };
      if (unit != ingame->player && unit->health < 1.0 && unit->health > 0)
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

  int wcnt = 0;

  if (ingame->fire)
    {
      t_bunny_area	cam = {
	ingame->camera.x - ingame->camera.w / 2,
	ingame->camera.y - ingame->camera.h / 2,
	2 * ingame->program->screen->buffer.width,
	2 * ingame->program->screen->buffer.height
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

      unsigned int fcol = ALPHA(16, TO_RED(128) | TO_GREEN(64) | TO_BLUE(64));
      fire(ingame->fire, false, &cam);
      for (int j = starty; j < endy; ++j)
	for (int i = startx; i < endx; ++i)
	  {
	    t_bunny_position fpos = {i - ingame->camera.x, j - ingame->camera.y};
	    int tile = ingame->physic_map[i + j * ingame->map_size.x];
	    t_bunny_position fsize = {30, 30};
	    
	    if (tile == FIRE)
	      {
		fsize.y = (fsize.x += rand() % 20) - 5;
		bunny_set_disk(&ingame->whitescreen->buffer, fpos, fsize, fcol, 0, 0);
		set_fire_pixel(i, j);
		if (distance(i, j,
			     ingame->player->area.x + ingame->player->area.w / 2,
			     ingame->player->area.y) < pow(fsize.x * 1.2, 2))
		  ingame->enlighted = true;
	      }
	    t_bunny_bitfield *wt = ingame->water_map[ingame->current_water_map];

	    if (BITGET(wt, i, j, ingame->map_size.x))
	      {
		int val = rand() % 128 + 128;
		unsigned int dcol = TO_BLUE(val);
		
		dcol |= TO_GREEN(128 + rand() % (val - 127));
		dcol = ALPHA(128, dcol);
		// dcol = rand() | BLACK;
		bunny_set_pixel(&ingame->program->screen->buffer, fpos, dcol);
		fpos.y += 1;
		bunny_set_pixel(&ingame->program->screen->buffer, fpos, dcol);
		wcnt += 1;
	      }
	  }
    }

  if (ingame->fire)
    {
      bunny_clipable_copy(&ingame->fire->clipable, &ingame->color_map->clipable);
      bunny_blit(&ingame->program->screen->buffer, &ingame->fire->clipable, NULL);
    }

  if (ingame->foreground)
    {
      bunny_clipable_copy(ingame->foreground, &ingame->color_map->clipable);
      bunny_blit(&ingame->program->screen->buffer, ingame->foreground, NULL);
    }

  check_particule(ingame);

  if (ingame->program->no_light == false)
    {
      bunny_set_multiply_blit(true);
      bunny_blit(&ingame->program->screen->buffer, ingame->whitescreen, NULL);
      bunny_set_multiply_blit(false);
    }

  // Les spectres! Par dessus l'ombre...
  bunny_clipable_copy(ingame->specter_map, &ingame->color_map->clipable);
  bunny_clipable_copy(ingame->specter_mask, &ingame->color_map->clipable);
  bunny_set_multiply_blit(true);
  bunny_blit(&ingame->specter_map->buffer, ingame->specter_mask, NULL);
  bunny_set_multiply_blit(false);  
  bunny_blit(&ingame->program->screen->buffer, ingame->specter_map, NULL);

  ///////////////// GUI /////////////////
  ingame_display_order_areas(ingame);
  ingame_display_health_bar(ingame);
  ingame_display_selection(ingame);
  ingame_display_life(ingame);
  ingame_display_mouse(ingame);
  
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

  if (ingame->enlighted)
    ingame->last_enlightnment = bunny_get_current_time();
  
  return (GO_ON);
}


