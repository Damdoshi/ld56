// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"sgsplash.h"

t_bunny_response		sgsplash_key(t_bunny_event_state	state,
					    t_bunny_keysym		sym,
					    t_sgsplash			*spa)
{
  (void)spa;
  if (state == GO_UP)
    return GO_ON;
  if (sym == BKS_SPACE || sym == BKS_ESCAPE)
    {
      return SWITCH_CONTEXT;
    }
  return (GO_ON);
}
