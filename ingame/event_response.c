// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"

t_bunny_response	ingame_event_response(const t_bunny_event	*event,
					      t_ingame		*ingame)
{
  (void)event;
  (void)ingame;
  return (GO_ON);
}
