// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

t_bunny_response	sgsplash_loop(t_sgsplash		*spa)
{
  spa->now_time = bunny_get_current_time();
  if (spa->now_time - spa->start_time >= spa->duration)
    {
      return (SWITCH_CONTEXT);
    }
  return (GO_ON);
}

