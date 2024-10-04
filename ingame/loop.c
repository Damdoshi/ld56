// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"

t_bunny_response	ingame_loop(t_ingame		*ingame)
{
  bunny_sprite_animate_now(ingame->mmx);
  return (GO_ON);
}

