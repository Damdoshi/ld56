
#include		"program.h"

void			ingame_unselect_unit(t_ingame		*ing,
					     t_unit		*unit)
{
  if (!unit->selected)
    return ;
  for (size_t i = 0; i < ing->last_selection; ++i)
    {
      if (ing->selection[i] == unit)
	{
	  unit->selected = false;
	  ing->selection[i] = ing->selection[--ing->last_selection];
	  return ;
	}
    }
}
