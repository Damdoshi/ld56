// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"cinematic.h"

t_bunny_response	cinematic_key(t_bunny_event_state		state,
				      t_bunny_keysym			sym,
				      t_cinematic			*cinematic);

t_bunny_response	cinematic_joy_button(t_bunny_event_state	state,
					     int			joyid,
					     int			button,
					     t_cinematic		*cinematic)
{
  (void)joyid;
  if (button == 6)
    return (cinematic_key(state, BKS_ESCAPE, cinematic));
  return (cinematic_key(state, BKS_SPACE, cinematic));
}

