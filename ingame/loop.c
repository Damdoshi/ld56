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
  ingame->frames +=1;
  if (ingame_progress_health(ingame) == false)
    {
      if (ingame->life-- > 0)
	return (SWITCH_CONTEXT);
      ingame->program->context = CINEMATIC;
      ingame->program->cinematic.following_context = MAIN_MENU;
      return (SWITCH_CONTEXT);
    }
  for (size_t i = 0; i < ingame->last_sprite; ++i)
    bunny_sprite_animate_now(ingame->sprites[i]);
  butcher(ingame);
  return (GO_ON);
}

