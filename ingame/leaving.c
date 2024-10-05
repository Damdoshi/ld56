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
  if (response == EXIT_ON_ERROR || response == EXIT_ON_SUCCESS)
    return ;
  if (response == SWITCH_CONTEXT && ingame->program->context == INGAME)
    return ;
  ingame_free_sprite(ingame, &ingame->cursor);
  ingame_free_sprite(ingame, &ingame->health_track);
  ingame_free_sprite(ingame, &ingame->health_bar);
  ingame_free_sprite(ingame, &ingame->health_renderer);
  ingame_free_sprite(ingame, &ingame->skull);
  fire(NULL, false);
}

