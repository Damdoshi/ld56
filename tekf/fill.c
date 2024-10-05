/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2015
**
** TekFunction
*/

#include		"tekfunction.h"

void			tekfill(t_bunny_pixelarray	*pix,
				unsigned int		color)
{
  t_bunny_position	pos;
  t_bunny_position	len;

  len.x = pix->clipable.clip_x_position + pix->clipable.clip_width;
  len.y = pix->clipable.clip_y_position + pix->clipable.clip_height;
  for (pos.y = pix->clipable.clip_y_position; pos.y < len.y; ++pos.y)
    for (pos.x = pix->clipable.clip_x_position; pos.x < len.x; ++pos.x)
      tekpixel(pix, pos, color);
}

