
#include		"program.h"

void			ingame_display_selection(t_ingame	*ing)
{
  if (ing->select_on)
    draw_rect(ing, &ing->select);
  for (size_t i = 0; i < ing->last_selection && i < NBRCELL(ing->selection); ++i)
    draw_rect(ing, &ing->selection[i]->area);
}
