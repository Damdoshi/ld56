#include		"program.h"

static void		moderate_forces(t_ingame	*ing,
					t_unit		*unit)
{
  if (ingame_bottom_collision(ing, unit))
    {
      if (unit->inertia.y > 6)
	ingame_get_hurt(ing, (unit->inertia.y - 6) / 4.0);
      else if (unit->inertia.y > 0.5)
	{} // Faire un bruit de bobo - mais on est pas blessé
      unit->inertia.y = 0;
    }
  else
    {
      if (unit->inertia.y > 0)
	unit->inertia.y = bunny_clamp(unit->inertia.y * 1.001, -10, 10);
      else
	unit->inertia.y = bunny_clamp(unit->inertia.y * 0.999, -10, 10);
    }
  
  if (fabs(unit->inertia.x) > 0.01)
    {
      if (ingame_bottom_collision(ing, unit))
	unit->inertia.x *= 0.90;
      else
	unit->inertia.x *= 0.95;
    }
  else
    unit->inertia.x = 0;
}

static void		check_bottom(t_ingame		*ingame,
				     t_unit		*unit)
{
  int			side_size;
  int			n_move;
  int			i;

  side_size = unit->area.w / 2;
  n_move = 0;
  while (n_move < unit->inertia.y)
    {
      i = 0;
      while (i < side_size)
	{
	  // y + 1 pour check sous les pieds
	  if (ingame_get_pixel(ingame, unit->area.x + i, unit->area.y + 1) != AIR
	      || ingame_get_pixel(ingame, unit->area.x - i, unit->area.y + 1) != AIR)
	    return;
	  i += 1;
	}
      unit->inertia.y += 1;
      n_move += 1;
    }
}

static void		check_top(t_ingame		*ingame,
				  t_unit		*unit)
{
  int			side_size;
  int			i;
  int			y;
  int			n_move;

  side_size = unit->area.w / 2;
  // y + 1 pour check sous les pieds
  y = unit->area.y - unit->area.h - 1;
  n_move = 0;
  while (n_move < -unit->inertia.y)
    {
      i = 0;
      while (i < side_size)
	{
	  if (ingame_get_pixel(ingame, unit->area.x + i, y) != AIR
	      || ingame_get_pixel(ingame, unit->area.x - i, y) != AIR)
	      return;
	  i += 1;
	}
      n_move += 1;
      unit->area.y -= 1;
    }
}

static void		check_side(t_ingame		*ingame,
				   int			side,
				   t_unit		*unit)
{
  int			x;
  int			side_size;
  int			i;
  int			n_move;

  n_move = 0;
  side_size = unit->area.w / 2;
  x = unit->area.x + (side_size + 1) * side;    
  while (n_move < unit->inertia.x)
    {
      i = 0;
      while (i < unit->area.h)
	{
	  if (ingame_get_pixel(ingame, x, unit->area.y - i) != AIR)
	    return;
	  i += 1;
	}
      unit->area.x += side;
      n_move += 1;
    }
}

void			manage_inertia(t_ingame		*ingame,
				       t_unit		*unit)
{
  moderate_forces(ingame, unit);
  unit->area.x += unit->inertia.x;
  unit->area.y += unit->inertia.y;
  return ;
  
  if (unit->inertia.y < 0)
    check_bottom(ingame, unit);
  else if (unit->inertia.y > 0)
    check_top(ingame, unit);
  if (unit->inertia.x < 0)
    check_side(ingame, -1, unit);
  else if (unit->inertia.x > 0)
    check_side(ingame, 1, unit);
}
