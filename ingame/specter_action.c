
#include		"program.h"

void			ingame_specter_action(t_ingame	*ingame,
					      t_unit	*unit)
{
  double		ang;
  double		x = ingame->player->area.x - unit->area.x;
  double		y = (ingame->player->area.y -ingame->player->area.h / 2) - unit->area.y;

  ang = 180.0 * atan2(y, x) / M_PI;
  unit->sprite->clipable.rotation = ang;
  
}


