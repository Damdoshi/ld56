// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

t_bunny_response	sgsplash_entering(t_sgsplash		*spa)
{
  uint32_t		i = 0;
  t_bunny_color		col;
  t_bunny_position	pos;
  t_bunny_picture	*pic;
  t_bunny_picture	*pix;
  t_bunny_pixelarray	*pixx;

  spa->win = spa->program->window;
  spa->current_context = &spa->program->context;
  if ((pic = bunny_new_picture(spa->win->buffer.width, spa->win->buffer.height)) == NULL)
    return (EXIT_ON_ERROR);
  if ((pix = bunny_new_picture(spa->win->buffer.width, spa->win->buffer.height)) == NULL)
    return (EXIT_ON_ERROR);
  if ((pixx = bunny_new_pixelarray(spa->win->buffer.width, spa->win->buffer.height)) == NULL)
    return (EXIT_ON_ERROR);
  if ((spa->pix = bunny_load_pixelarray("res/sgsplash/galax.png")) == NULL)
    return (EXIT_ON_ERROR);
  if ((spa->pic = bunny_load_picture("res/sgsplash/galax.png")) == NULL)
    return (EXIT_ON_ERROR);
  spa->pic->scale.x = (double)pic->buffer.width / (double)spa->pic->buffer.width;//spa->pic->buffer.width / pic->buffer.width;
  spa->pic->scale.y = (double)pic->buffer.height / (double)spa->pic->buffer.height;//spa->pic->buffer.height / pic->buffer.height;
  spa->pix->clipable.scale.x = (double)pix->buffer.width / (double)spa->pix->clipable.buffer.width;//spa->pix->clipable.buffer.width / pix->clipable.buffer.width;
  spa->pix->clipable.scale.y = (double)pix->buffer.height / (double)spa->pix->clipable.buffer.height;//spa->pix->clipable.buffer.height / pix->clipable.buffer.height;
  bunny_blit(&pix->buffer, &spa->pix->clipable, NULL);
  bunny_blit(&pixx->clipable.buffer, pix, NULL);
  bunny_blit(&pic->buffer, spa->pic, NULL);
  bunny_delete_clipable(&spa->pix->clipable);
  bunny_delete_clipable(spa->pic);
  bunny_delete_clipable(pix);
  spa->pix = pixx;
  spa->pic = pic;
  if ((spa->font = bunny_load_text("res/sgsplash/compagnie_name.dab")) == NULL)
    return (EXIT_ON_ERROR);
  spa->duration = 8.0;
  spa->rot.x = 0;
  spa->rot.y = 0;
  spa->rot.z = M_PI / 1500;
  spa->pos.x = spa->pix->clipable.buffer.width / 2;
  spa->pos.y = spa->pix->clipable.buffer.height / 2;
  if ((spa->pts = (t_zposition*)(malloc(sizeof(t_zposition) * (spa->pix->clipable.buffer.width * spa->pix->clipable.buffer.height)))) == NULL)
    return (EXIT_ON_ERROR);
  memset(spa->pts, 0, (sizeof(t_zposition) * (spa->pix->clipable.buffer.width * spa->pix->clipable.buffer.height)));
  if ((spa->col = (uint32_t*)(malloc(sizeof(uint32_t) * (spa->pix->clipable.buffer.width * spa->pix->clipable.buffer.height)))) == NULL)
    return (EXIT_ON_ERROR);
  memset(spa->col, 0, (sizeof(uint32_t) * (spa->pix->clipable.buffer.width * spa->pix->clipable.buffer.height)));
  spa->color.full = BLACK;
  spa->color.argb[3] = 255;
  spa->font->clipable.color_mask.argb[ALPHA_CMP] = 16;
  spa->nb_pts = 0;
  for (int32_t y = 0; y < spa->pix->clipable.buffer.height; y++)
    for (int32_t x = 0; x < spa->pix->clipable.buffer.width; x++)
      {
        pos.x = x;
        pos.y = y;
        col.full = get_pixel(spa->pix, pos);
        if (col.argb[3] != 0)
          {
            spa->pts[i].x = x - spa->pos.x;
	    spa->pts[i].y = y - spa->pos.y;
            spa->pts[i].z = 0;
            spa->col[i] = col.full;
	    spa->nb_pts ++;
            i ++;
          }
      }
  spa->start_time = spa->now_time = bunny_get_current_time();
  return (GO_ON);
}

