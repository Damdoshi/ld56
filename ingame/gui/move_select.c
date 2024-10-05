
#include		"program.h"

void			ingame_move_select(t_ingame		*ing)
{
  t_bunny_position	pos = ingame_get_real_mouse_position(ing);

  // Selection possible dans toutes les direction
  if ((ing->select.w = pos.x - ing->select.x) < 0)
    {
      ing->select.x += ing->select.w;
      ing->select.w *= 1;
    }
  if ((ing->select.h = pos.y - ing->select.y) < 0)
    {
      ing->select.y += ing->select.h;
      ing->select.h *= 1;
    }
}
