/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2015
**
** TekFunction
*/

#include		"tekfunction.h"

void			tekclear(t_bunny_pixelarray		*pix,
				 unsigned int			color)
{
  int			len;
  int			i;

  for (i = 0, len = pix->clipable.buffer.width * pix->clipable.buffer.height; i < len; ++i)
    ((int*)pix->pixels)[i] = color;
}

