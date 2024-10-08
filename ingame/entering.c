// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"

t_bunny_response	ingame_entering(t_ingame		*ingame)
{
  bunny_clear(&ingame->program->window->buffer, BLACK);
  assert(ingame_load_map(ingame, "./res/ingame/level/00/configuration.dab"));

  ingame_load_sprite(ingame, "./res/ingame/gfx/cursor.dab", &ingame->cursor);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_track.dab", &ingame->health_track);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_bar.dab", &ingame->health_bar);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_renderer.dab", &ingame->health_renderer);
  ingame_load_sprite(ingame, "./res/ingame/gfx/aura.dab", &ingame->aura);
  ingame_load_sprite(ingame, "./res/ingame/gfx/skull.dab", &ingame->skull);
  bunny_sound_play(&(bunny_load_music("res/music/music.ogg")->sound));
  ingame->particules.nb_particule = 0;
  ingame->cursor_type = SELECTION;

  assert((ingame->whitescreen = bunny_new_picture(ingame->program->screen->buffer.width, ingame->program->screen->buffer.height)));
  assert((ingame->action_screen = bunny_new_pixelarray(ingame->program->screen->buffer.width, ingame->program->screen->buffer.height)));

  ingame->brush_size = 5;
  ingame->health = 1;
  assert((ingame->music = bunny_load_music("./res/ingame/music.ogg")));
  bunny_sound_play(&ingame->music->sound);
  return (GO_ON);
}

