
#include		"program.h"

void			ingame_delete_unit(t_ingame	*ing,
					   t_unit	*unit)
{
  ingame_free_sprite(ing, &unit->sprite);
  memcpy(unit, &ing->units[--ing->last_unit], sizeof(*unit));
}

