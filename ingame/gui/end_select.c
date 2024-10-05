
#include		"program.h"

void			ingame_end_select(t_ingame	*ing)
{
  size_t		i;

  ing->select_on = false;

  // On détermine via la dernière position de la souris la vraie selection.
  ingame_move_select(ing);

  // La politique de selection - si c'est une nouvelle, on détruit l'ancienne
  if (!bunny_get_keyboard()[BKS_LSHIFT] && !bunny_get_keyboard()[BKS_RSHIFT])
    {
      for (i = 0; i < ing->last_selection; ++i)
	ing->units[i].selected = false;
      ing->last_selection = 0;
    }
  // La zone de selection traduite dans l'espace de jeu
  t_bunny_accurate_area	area = {
    .x = ing->select.x + ing->camera.x,
    .y = ing->select.y + ing->camera.y,
    .w = ing->camera.w,
    .h = ing->camera.h
  };

  // Et on rafraichit la selection
  for (i = 0; i < ing->last_unit && i < NBRCELL(ing->units); ++i)
    if (ing->units[i].selected)
      continue ;
    else if (!bunny_rectangular_collision(&area, &ing->units[i].area))
      continue ;
    else
      {
	ing->selection[ing->last_selection] = &ing->units[i];
	ing->units[i].selected = true;
	if ((ing->last_selection += 1) >= NBRCELL(ing->selection))
	  break ;
      }
}
