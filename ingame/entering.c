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
  ingame_load_sprite(ingame, "./res/ingame/gfx/cursor.dab", &ingame->cursor);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_track.dab", &ingame->health_track);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_bar.dab", &ingame->health_bar);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_renderer.dab", &ingame->health_renderer);
  ingame_load_sprite(ingame, "./res/ingame/gfx/skull.dab", &ingame->skull);
  bunny_clear(&ingame->program->window->buffer, BLACK);
  
  ingame->health = ingame->health_target = 1;
  return (GO_ON);
}

