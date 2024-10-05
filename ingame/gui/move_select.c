
#include		"program.h"

void			ingame_move_select(t_ingame		*ing)
{
  t_bunny_position	pos = get_real_mouse_position(ing->program->screen);

  ing->select.w = pos.x - ing->select.x;
  ing->select.h = pos.y - ing->select.y;
}
