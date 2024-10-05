/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2015
**
** TekFunction
*/

#include		"tekfunction.h"

static void		color_coef(t_color					*color,
				   const t_color				*from,
				   const t_color				*to,
				   int						cursor,
				   int						length)
{
  int			i;

  for (i = RED_CMP; i < ALPHA_CMP + 1; ++i)
    {
      double		coef;

      coef = (to->argb[i] - from->argb[i]) / (double)length;
      color->argb[i] = from->argb[i] + cursor * coef;
    }
}

static void		draw_line(t_bunny_pixelarray				*pix,
				  const t_bunny_position			*a,
				  const t_bunny_position			*b,
				  const t_color					*cola,
				  const t_color					*colb)
{
  t_color		color;
  t_bunny_position	pos;
  double		coef;
  double		i;
  int			direction;

  direction = b->x - a->x;
  if (b->x - a->x == 0 || (coef = (double)(b->y - a->y) / direction) > 1 || coef < -1)
    {
      if ((direction = b->y - a->y) == 0)
	{
	  tekpixel(pix, *a, cola->full);
	  return ;
	}
      coef = (double)(b->x - a->x) / direction;
      for (i = a->y; i != b->y; i += (direction > 0) ? 1 : -1)
	{
	  color_coef(&color, cola, colb, i - a->y, direction);
	  pos.x = coef * (i - a->y) + a->x;
	  pos.y = i;
	  tekpixel(pix, pos, color.full);
	}
    }
  else
    for (i = a->x; i != b->x; i += (direction > 0) ? 1 : -1)
      {
	color_coef(&color, cola, colb, i - a->x, direction);
	pos.x = i;
	pos.y = coef * (i - a->x) + a->y;
	tekpixel(pix, pos, color.full);
      }
}

void			tekline(t_bunny_pixelarray		*pix,
				const t_bunny_position		*pos,
				const unsigned int		*color)
{
  draw_line(pix, &pos[0], &pos[1], (t_color*)&color[0], (t_color*)&color[1]);
}

