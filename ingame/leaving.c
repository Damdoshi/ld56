// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"

void			ingame_leaving(t_bunny_response	response,
				       t_ingame		*ingame)
{
  bunny_sound_stop(&ingame->music->sound);
  if (ingame->program->context == CREDIT)
    return ;
  (void)response;
  fire(NULL, false, NULL);
  bunny_delete_clipable(ingame->background);
  bunny_delete_clipable(ingame->foreground);
  bunny_delete_clipable(ingame->remain_map);
  bunny_delete_clipable(&ingame->action_screen->clipable);
  bunny_delete_clipable(&ingame->color_map->clipable);
  bunny_delete_clipable(ingame->whitescreen);
  bunny_delete_clipable(ingame->specter_map);
  free(ingame->physic_map);
  for (size_t i = 0; i < ingame->last_sprite; ++i)
    bunny_delete_clipable(&ingame->sprites[i]->clipable);
  bunny_delete_sound(&ingame->music->sound);
  ingame->cursor = NULL;
  ingame->health_track = NULL;
  ingame->health_bar = NULL;
  ingame->health_renderer = NULL;
  ingame->aura = NULL;
  ingame->skull = NULL;
  memset(ingame->units, 0, sizeof(ingame->units));
  memset(ingame->sprites, 0, sizeof(ingame->sprites));
  memset(&ingame->particules, 0, sizeof(ingame->particules));
  memset(ingame->selection, 0, sizeof(ingame->selection));
  ingame->player = NULL;
  ingame->last_sprite = 0;
  ingame->particules.nb_particule = 0;
  ingame->last_selection = 0;
  ingame->last_unit = 0;
}

