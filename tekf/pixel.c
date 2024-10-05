/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2015
**
** TechnoCore
*/

#include		"tekfunction.h"

void			tekpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	pos,
				 unsigned int		color)
{
  t_color		res;
  t_color		ori;
  t_color		lay;
  double		under_ratio;
  double		upper_ratio;
  int			i;

  if (pos.x >= pix->clipable.buffer.width ||
      pos.y >= pix->clipable.buffer.height ||
      pos.x < 0 || pos.y < 0)
    return ;
  lay.full = color;
  if (lay.argb[ALPHA_CMP] == 255)
    ((unsigned int*)pix->pixels)[pos.x + pos.y * pix->clipable.buffer.width] = color;
  else
    {
      res.full = 0;
      ori.full = ((unsigned int*)pix->pixels)[pos.x + pos.y * pix->clipable.buffer.width];

      upper_ratio = (double)lay.argb[ALPHA_CMP] / 255.0;
      under_ratio = (double)(255 - lay.argb[ALPHA_CMP]) / 255.0;

      res.argb[ALPHA_CMP] = 255;
      for (i = RED_CMP; i < ALPHA_CMP; ++i)
	res.argb[i] = ori.argb[i] * under_ratio + lay.argb[i] * upper_ratio;

      ((unsigned int*)pix->pixels)[pos.x + pos.y * pix->clipable.buffer.width] = res.full;
    }
}
