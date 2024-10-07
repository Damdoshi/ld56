
#include		"program.h"

void			ingame_brush(t_ingame		*ing,
				     t_bunny_bitfield	*bf,
				     bool		add,
				     int		cursor)
{
  t_bunny_position	m = get_real_mouse_position(ing->program->screen);

  m.x += ing->camera.x;
  m.y += ing->camera.y;
  
  int			startx = m.x - ing->cursor->clipable.clip_width;
  int			starty = m.y - ing->cursor->clipable.clip_height;
  int			endx = m.x + ing->cursor->clipable.clip_width;
  int			endy = m.y + ing->cursor->clipable.clip_height;
  int			rad = ing->brush_size;

  rad *= rad;
  if (add)
    {
      for (int j = starty; j < endy; ++j)
	for (int i = startx; i < endx; ++i)
	  {
	    int px = ingame_get_pixel(ing, i, j);

	    if (cursor == ATTACK)
	      {
		if (px == EARTH || px == EXPLODE || px == SAND)
		  if (distance(i, j, m.x, m.y) < rad)
		    BITSET(bf, i, j, ing->map_size.x);
	      }
	    else if (cursor == CONSTRUCTION)
	      {
		if (px == AIR)
		  if (distance(i, j, m.x, m.y) < rad)
		    BITSET(bf, i, j, ing->map_size.x);
	      }
	  }
    }
  else
    {
      for (int j = starty; j < endy; ++j)
	for (int i = startx; i < endx; ++i)
	  if (distance(i, j, m.x, m.y) < rad)
	    BITCLR(bf, i, j, ing->map_size.x);
    }
}

