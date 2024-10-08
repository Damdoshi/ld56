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
  ingame->player = NULL;
  ingame->last_sprite = 0;
  ingame->particules.nb_particule = 0;
  ingame->last_selection = 0;
  ingame->last_unit = 0;
  
  char			buffer[4096];

  snprintf(buffer, sizeof(buffer), "./res/ingame/level/%02d/configuration.dab", ingame->current_level);
  if (ingame_load_map(ingame, buffer) == false)
    {
      ingame->program->context = CREDIT;
      return (SWITCH_CONTEXT);
    }
  
  ingame_load_sprite(ingame, "./res/ingame/gfx/cursor.dab", &ingame->cursor);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_track.dab", &ingame->health_track);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_bar.dab", &ingame->health_bar);
  ingame_load_sprite(ingame, "./res/ingame/gfx/health_renderer.dab", &ingame->health_renderer);
  ingame_load_sprite(ingame, "./res/ingame/gfx/aura.dab", &ingame->aura);
  ingame_load_sprite(ingame, "./res/ingame/gfx/skull.dab", &ingame->skull);
  ingame->particules.nb_particule = 0;
  ingame->cursor_type = SELECTION;	      
  
  assert((ingame->whitescreen = bunny_new_picture(ingame->program->screen->buffer.width, ingame->program->screen->buffer.height)));
  assert((ingame->action_screen = bunny_new_pixelarray(ingame->program->screen->buffer.width, ingame->program->screen->buffer.height)));

  ingame->brush_size = 10;
  ingame->health = 1;
  assert((ingame->music = bunny_load_music("./res/ingame/music.ogg")));
  bunny_sound_play(&ingame->music->sound);
  ingame->waterline = ingame->map_size.y - 1;
  return (GO_ON);
}

