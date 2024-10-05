
#include		"program.h"

void			ingame_load_sprite(t_ingame		*ingame,
					   const char		*file,
					   t_bunny_sprite	**sprite)
{
  if (*sprite)
    return ;
  assert((*sprite = bunny_load_sprite(file)));
  ingame->sprites[ingame->last_sprite++] = *sprite;
}
