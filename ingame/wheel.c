// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"ingame.h"

t_bunny_response		ingame_wheel(int			wheel,
					      int			delta,
					      t_ingame			*ingame)
{
  (void)wheel;

  if (delta > 0)
    if ((ingame->brush_size += 1) > 15)
      ingame->brush_size = 15;

  if (delta < 0)
    if ((ingame->brush_size -= 1) < 5)
      ingame->brush_size = 5;

  return (GO_ON);
}
