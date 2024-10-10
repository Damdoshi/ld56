
#include		"program.h"

void			ingame_display_selection(t_ingame	*ing)
{
  if (ing->select_on)
    draw_rect(ing, &ing->select);
  /*
  for (size_t i = 0; i < ing->last_selection && i < NBRCELL(ing->selection); ++i)
    {
      t_bunny_accurate_area	*are = &ing->selection[i]->area;
      t_bunny_accurate_area	area = {
	are->x - are->w / 2,
	are->y - are->y / 2,
	are->w, are->h
      };
 
      draw_rect(ing, &area);
    }
  */
}
