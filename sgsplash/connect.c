// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

t_bunny_response	sgsplash_connect(int			fd,
					t_bunny_event_state	state,
					t_sgsplash		*sgsplash)
{
  (void)fd;
  (void)state;
  (void)sgsplash;
  return (GO_ON);
}
