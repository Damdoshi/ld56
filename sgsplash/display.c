// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

t_bunny_response	sgsplash_display(t_sgsplash	*spa)
{
  double		ratio;
  double		lratio;

  ratio = (spa->now_time - spa->start_time) / spa->duration;
  if (ratio < 0.25)
    {
      lratio = ratio / 0.25;
      bunny_clear(&spa->win->buffer, BLACK);
      spa->pic->origin.x = spa->pic->buffer.width / 2;
      spa->pic->origin.y = spa->pic->buffer.height / 2;
      spa->pic->position.x = spa->pic->buffer.width / 2;
      spa->pic->position.y = spa->pic->buffer.height / 2;
      if (spa->pic->rotation < 2 * 360)
	spa->pic->rotation = 2 * 360 * (lratio * lratio);
    }
  if (ratio >= 0.25
      && ratio < 0.50)
    {
      efclear_pixelarray(spa->pix, BLACK);
      t_bunny_position  pos;

      int32_t y;
      for (uint32_t i = 0; i < spa->nb_pts; i++)
        {
          y = (spa->pts[i].y) /5;
          spa->pts[i].y -= y * ratio * ratio;
          pos.x = spa->pts[i].x + spa->pos.x;
          pos.y = (spa->pts[i].y + spa->pos.y);
          efset_pixel(spa->pix, pos, spa->col[i]);
        }
    }
  else if (ratio >= 0.50
	   && ratio < 0.75)
    {
      efclear_pixelarray(spa->pix, BLACK);
      boom_galax(spa);
    }
  if (ratio > 0.25)
    {
      bunny_clear(&spa->win->buffer, BLACK);
      if (ratio < 0.75)
	bunny_blit(&spa->win->buffer, &spa->pix->clipable, NULL);
      if (ratio >= 0.50 && ratio < 1)
	app_nom(spa, ratio);
      bunny_display(spa->win);
    }
  else
    {
      bunny_clear(&spa->win->buffer, BLACK);
      bunny_blit(&spa->win->buffer, spa->pic, NULL);
      bunny_display(spa->win);
    }
  return (GO_ON);
}

