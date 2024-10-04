// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"

t_bunny_response	ingame_entering(t_ingame		*ingame)
{
  assert((ingame->mmx = bunny_load_sprite("./res/ingame/gfx/sprite.dab")));
  return (GO_ON);
}

