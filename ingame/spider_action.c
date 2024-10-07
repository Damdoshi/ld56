
#include		"program.h"

void			ingame_spider_action(t_ingame	*ingame,
					     t_unit	*unit)
{
  for (size_t i = 0; i < ingame->last_unit && i < NBRCELL(ingame->units); i++)
    if (unit[i].selected)
      {
	if (unit[i].area.x > unit[i].target.x)
	  ingame_go(ingame, &unit[i], -1);
	else
	  ingame_go(ingame, &unit[i], 1);
      }
}
