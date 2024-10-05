/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2015
**
** TekFunction
*/

#include		"tekfunction.h"

typedef struct		s_bunny_square
{
  int			left;
  int			top;
  int			right;
  int			bottom;
}			t_bunny_square;

void			tekblit(t_bunny_pixelarray			*out,
				const t_bunny_pixelarray		*in,
				const t_bunny_position			*pos)
{
  static const t_bunny_position defaul = {0, 0};
  t_bunny_square	destination;
  t_bunny_position	i;
  t_bunny_position	e;

  if (pos == NULL)
    pos = &defaul;
  destination.left = pos->x;
  destination.top = pos->y;
  destination.right = destination.left + in->clipable.clip_width * in->clipable.scale.x;
  destination.bottom = destination.top + in->clipable.clip_height * in->clipable.scale.y;
  for (i.y = destination.top; i.y < destination.bottom; ++i.y)
    for (i.x = destination.left; i.x < destination.right; ++i.x)
      {
	e.x = in->clipable.clip_width *
	  (double)(i.x - destination.left) / (destination.right - destination.left)
	  + in->clipable.clip_x_position;
	e.y = in->clipable.clip_height *
	  (double)(i.y - destination.top) / (destination.bottom - destination.top) +
	  + in->clipable.clip_y_position;
	tekpixel(out, i, ((int*)in->pixels)[e.x + e.y * in->clipable.buffer.width]);
      }
}

