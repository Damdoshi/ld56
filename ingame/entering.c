// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"
#include		"load_file.h"

t_bunny_response	ingame_entering(t_ingame		*ingame)
{
  ingame_load_sprite(ingame, "./res/ingame/gfx/cursor.dab", &ingame->cursor);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_track.dab", &ingame->health_track);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_bar.dab", &ingame->health_bar);
  assert((ingame->health_renderer = bunny_new_picture
	  (ingame->health_track->clipable.buffer.width - ingame->health_track->clipable.position.x * 2,
	   ingame->health_track->clipable.buffer.height)
	  ));
  ingame->player_pic = bunny_load_picture("./res/ingame/gfx/hero.dab");

  ingame->map = load_map(bunny_load_pixelarray("./res/ingame/TestPhysiqueMap.png"));
  if (!ingame->map)
    return(EXIT_ON_ERROR);
  ingame->layer[0] = NULL; // Car pas encore la ressource
  ingame->layer[1] = ingame->map->map;
  ingame->layer[2] = NULL;
  ingame->player.type = HERO;
  ingame->player.area.w = 50;
  ingame->player.area.h = 50;
  ingame->player.area.x = 0;
  ingame->player.area.y = 0;
  bunny_clear(&ingame->program->window->buffer, BLACK);
  return (GO_ON);
}

