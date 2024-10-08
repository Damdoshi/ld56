// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

t_bunny_response	sgsplash_joy_axis(int				joyid,
					 t_bunny_axis			axis,
					 float				value,
					 t_sgsplash			*sgsplash)
{
  (void)joyid;
  (void)axis;
  (void)value;
  (void)sgsplash;
  return (GO_ON);
}

