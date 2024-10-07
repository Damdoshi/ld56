
#include		"program.h"

void			ingame_end_select(t_ingame	*ing)
{
  size_t		i;

  if (ing->select_on == false)
    return ;
  ing->select_on = false;

  // On détermine via la dernière position de la souris la vraie selection.
  ingame_move_select(ing);

  // On conclu le rectangle final
  t_bunny_position pos = get_real_mouse_position(ing->program->screen);
  if (pos.x < ing->select.x)
    {
      ing->select.x = pos.x;
      ing->select.w *= -1;
    }
  if (pos.y < ing->select.y)
    {
      ing->select.y = pos.y;
      ing->select.h *= -1;
    }

  // La politique de selection - si c'est une nouvelle, on détruit l'ancienne
  if (!bunny_get_keyboard()[BKS_LSHIFT] && !bunny_get_keyboard()[BKS_RSHIFT])
    {
      for (i = 0; i < ing->last_selection; ++i)
	{
	  ing->selection[i]->selected = false;
	  ing->selection[i]->sprite->clipable.color_mask.full = WHITE;
	}
      ing->last_selection = 0;
    }
  // La zone de selection traduite dans l'espace de jeu

  t_bunny_accurate_area	area = {
    .x = ing->select.x + ing->camera.x,
    .y = ing->select.y + ing->camera.y,
    .w = ing->select.w,
    .h = ing->select.h
  };

  // Et on rafraichit la selection
  for (i = 0; i < ing->last_unit && i < NBRCELL(ing->units); ++i)
    if (ing->units[i].selected)
      continue ;
    else if (!bunny_rectangular_collision(&area, &ing->units[i].area))
      continue ;
    else
      {
	if (ing->last_selection >= NBRCELL(ing->selection))
	  break ;
	ing->selection[ing->last_selection] = &ing->units[i];
	ing->units[i].selected = true;
	ing->units[i].sprite->clipable.color_mask.full = RED;
	ing->last_selection += 1;
      }
}
