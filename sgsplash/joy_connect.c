// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

t_bunny_response	sgsplash_joy_connect(t_bunny_event_state		state,
					    int				joyid,
					    const t_bunny_joystick	*joystick,
					    t_sgsplash			*sgsplash)
{
  (void)state;
  (void)joyid;
  (void)joystick;
  (void)sgsplash;
  return (GO_ON);
}
