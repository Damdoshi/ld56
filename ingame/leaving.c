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
  (void)response;
  bunny_delete_clipable(&ingame->mmx->clipable);
}

