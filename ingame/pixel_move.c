#include		"program.h"

static bool		check_fall(t_ingame			*ing,
				   t_unit			*unit,
				   int				npos)
{
  int			i;
  int			nb_pixel = 0;
  int			side_size;

  side_size = unit->area.w / 2;
  nb_pixel = 0;
  if (ing->physic_map[npos] != AIR)
    nb_pixel += 1;
  i = 1;
  while (i < side_size)
    {
      if (ing->physic_map[npos + i] != AIR)
	nb_pixel += 1;
      if (ing->physic_map[npos - i] != AIR)
	nb_pixel += 1;
      i += 1;
    }
  if (nb_pixel < MIN_PIXEL_TO_HOLD)
    {
      unit->area.y += 1;
      return (true);
    }
  return (false);
}

static int		check_remaining_front(t_ingame		*ing,
					      t_unit		*unit,
					      int		npos,
					      int		i)
{
  while (i < unit->area.h
	 && ing->physic_map[npos - (ing->map_size.x * i)] == AIR)
    i += 1;
  if (i == unit->area.h)
    return(1);
  return(0);
}

static void		move_toward(t_ingame			*ing,
				    t_unit			*unit,
				    t_bunny_accurate_position	target_pos,
				    int				npos)
{
  int			direction;
  int			max_climbing_height;
  int			i;

  direction = (unit->area.x < target_pos.x) ? 1 : -1;
  // 1 pour check devant le personnage
  if (direction == 1)
      npos += (unit->area.w / 2) + 1;
  else
    npos -= (unit->area.w / 2) + 1;
  max_climbing_height = unit->area.h / COEF_CLIMBING_HEIGHT;
  i = 0;
  while (i < max_climbing_height && ing->physic_map[npos - (ing->map_size.x * i)] != AIR)
    i += 1;
  if (i < max_climbing_height)
    {
      unit->area.x += check_remaining_front(ing, unit, npos, i);
      unit->area.y -= i;
    }
}

void			pixel_move(t_ingame			*ingame,
				   t_unit			*unit,
				   t_bunny_accurate_position	target_pos)
{  
  int			npos;
  
  // + 1 pour check sous le personnage
  npos = (unit->area.y + 1) * ingame->map_size.x + unit->area.x;
  if (check_fall(ingame, unit, npos))
    return;
  if (unit->area.x == target_pos.x)
    return;
  move_toward(ingame, unit, target_pos, npos);
}
