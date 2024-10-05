
#include		"program.h"

void			ingame_free_sprite(t_ingame		*ingame,
					   t_bunny_sprite	**sprite)
{
  for (size_t i = 0; i < ingame->last_sprite && i < NBRCELL(ingame->sprites); ++i)
    if (ingame->sprites[i] == *sprite)
      {
	bunny_delete_clipable(&(*sprite)->clipable);
	*sprite = NULL;
	if (i != ingame->last_sprite)
	  ingame->sprites[i] = ingame->sprites[ingame->last_sprite - 1];
	ingame->last_sprite -= 1;
	return ;
      }
}
