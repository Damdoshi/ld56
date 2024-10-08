// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

t_bunny_response	sgsplash_joy_button(t_bunny_event_state		state,
					   int				joyid,
					   int				button,
					   t_sgsplash			*sgsplash)
{
  (void)state;
  (void)joyid;
  (void)button;
  (void)sgsplash;
  return (GO_ON);
}

