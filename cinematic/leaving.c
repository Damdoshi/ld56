// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"cinematic.h"

void			cinematic_leaving(t_bunny_response	response,
					t_cinematic		*cinematic)
{
  (void)response;
  bunny_delete_clipable(&cinematic->cinematic->clipable);
}

