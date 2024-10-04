// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"

t_bunny_response	ingame_joy_connect(t_bunny_event_state		state,
					    int				joyid,
					    const t_bunny_joystick	*joystick,
					    t_ingame			*ingame)
{
  (void)state;
  (void)joyid;
  (void)joystick;
  (void)ingame;
  return (GO_ON);
}
