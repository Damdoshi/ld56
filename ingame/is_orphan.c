
#include		"program.h"

bool			ingame_is_orphan(t_ingame	*ing,
					 int		x,
					 int		y)
{
  // Voisinage de Von Neumann
  int			type = ingame_get_pixel(ing, x, y);
  int			voisin;

  voisin = 0;
  voisin += ingame_get_pixel(ing, x - 1, y) == type;
  voisin += ingame_get_pixel(ing, x + 1, y) == type;
  voisin += ingame_get_pixel(ing, x, y - 1) == type;
  voisin += ingame_get_pixel(ing, x, y + 1) == type;
  return (voisin <= 1);
}

