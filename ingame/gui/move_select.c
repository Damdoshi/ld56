
#include		"program.h"

void			ingame_move_select(t_ingame		*ing)
{
  t_bunny_position	pos = ingame_get_real_mouse_position(ing);

  ing->select.w = pos.x - ing->select.x;
  ing->select.h = pos.y - ing->select.y;
}
