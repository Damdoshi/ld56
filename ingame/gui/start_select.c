
#include		"program.h"

void			ingame_start_select(t_ingame	*ing)
{
  if (ing->select_on)
    return ;
  t_bunny_position	pos = get_real_mouse_position(ing->program->screen);

  ing->select.x = pos.x;
  ing->select.y = pos.y;
  ing->select.w = 1;
  ing->select.h = 1;
  ing->select_on = true;
}

