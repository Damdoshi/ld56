#include		"movement.h"

#include		<stdbool.h>

static bool		check_fall(t_unit			*unit,
				   t_map			*env,
				   int				npos)
{
  int			i;
  int			nb_pixel;
  int			side_size;

  side_size = unit->area.w / 2;
  nb_pixel = 0;
  if (env->map_composant[npos] != AIR)
    nb_pixel += 1;
  i = 1;
  while (i < side_size)
    {
      if (env->map_composant[npos + i] != AIR)
	nb_pixel += 1;
      if (env->map_composant[npos - i] != AIR)
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

static int		check_remaining_front(t_unit		*unit,
					      t_map		*env,
					      int		npos,
					      int		i)
{
  while (i < unit->area.h
	 && env->map_composant[npos - (env->map->clipable.buffer.width * i)] == AIR)
    i += 1;
  if (i == unit->area.h)
    return(1);
  return(0);
}

static void		move_toward(t_unit			*unit,
				    t_bunny_accurate_position	target_pos,
				    t_map			*env,
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
  while (i < max_climbing_height
	 && env->map_composant[npos - (env->map->clipable.buffer.width * i)] != AIR)
    i += 1;
  if (i < max_climbing_height)
    {
      unit->area.x += check_remaining_front(unit, env, npos, i);
      unit->area.y -= i;
    }
}

void			pixel_move(t_unit			*unit,
				   t_bunny_accurate_position	target_pos,
				   t_map			*env)
{
  int			npos;
  
  // + 1 pour check sous le personnage
  npos = (unit->area.y + 1) * env->map->clipable.buffer.width + unit->area.x;
  if (check_fall(unit, env, npos))
    return;
  if (unit->area.x == target_pos.x)
    return;
  move_toward(unit, target_pos, env, npos);
}
