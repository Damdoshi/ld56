
#include		"program.h"

void			ingame_spider_action(t_ingame	*ingame,
					     t_unit	*unit)
{
  for (size_t i = 0; i < ingame->last_unit && i < NBRCELL(ingame->units); i++)
    if (unit[i].selected)
      {
	if (fabs(unit[i].area.x - unit[i].target.x) < 1)
	  {
	    unit[i].area.x = unit[i].target.x;
	    continue ;
	  }
	if (unit[i].area.x > unit[i].target.x)
	  ingame_go(ingame, &unit[i], -1);
	else if (unit[i].area.x < unit[i].target.x)
	  ingame_go(ingame, &unit[i], 1);
      }
}
