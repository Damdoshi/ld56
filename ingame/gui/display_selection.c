
#include		"program.h"

static void		draw_rect(t_ingame		*ing,
				  t_bunny_accurate_area	*area)
{
  unsigned int		color[2] = {
    COLOR(255, 128, 0, 0),
    COLOR(255, 255, 0, 0)
  };
  t_bunny_position	lines[5] = {
    [0] = {.x = area->x, .y = area->y},
    [1] = {.x = area->x + area->w, .y = area->y},
    [2] = {.x = area->x + area->w, .y = area->y + area->h},
    [3] = {.x = area->x, .y = area->y + area->h},
    [4] = {.x = area->x, .y = area->y}
  };

  for (size_t i = 0; i < NBRCELL(lines) - 1; ++i)
    bunny_set_line(&ing->program->screen->buffer, &lines[i], color);
}

void			ingame_display_selection(t_ingame	*ing)
{
  if (ing->select_on)
    draw_rect(ing, &ing->select);
  for (size_t i = 0; i < ing->last_selection && i < NBRCELL(ing->selection); ++i)
    draw_rect(ing, &ing->selection[i]->area);
}
