// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"cinematic.h"
#ifdef			LINUX
# define		ORIENTATION			>
#else
# define		ORIENTATION			<
#endif

t_bunny_response	cinematic_key(t_bunny_event_state	state,
				      t_bunny_keysym		sym,
				      t_cinematic		*cinematic);

t_bunny_response	cinematic_joy_axis(int			joyid,
					 t_bunny_axis		axis,
					 float			value,
					 t_cinematic		*cinematic)
{
  t_bunny_event_state	state = fabs(value) < 50 ? GO_UP : GO_DOWN;

  (void)joyid;
  if (axis == 0 || axis == 6) // Gauche droite
    return (cinematic_key(state, value < 0 ? BKS_LEFT : BKS_RIGHT, cinematic));
  else if (axis == 1) // Haut bas
    return (cinematic_key(state, value > 0 ? BKS_DOWN : BKS_UP, cinematic));
  else if (axis == 7) // pov
    return (cinematic_key(state, value ORIENTATION 0 ? BKS_DOWN : BKS_UP, cinematic));
  return (GO_ON);
}

