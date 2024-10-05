// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"credit.h"

t_bunny_response	credit_joy_connect(t_bunny_event_state		state,
					    int				joyid,
					    const t_bunny_joystick	*joystick,
					    t_credit			*credit)
{
  (void)state;
  (void)joyid;
  (void)joystick;
  (void)credit;
  return (GO_ON);
}
