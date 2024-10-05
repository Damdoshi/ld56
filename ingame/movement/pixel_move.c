#include		"movement.h"

#include		<stdbool.h>

static bool		check_fall(t_unit			*unit,
				   t_bunny_accurate_position	target_pos,
				   unsigned int			*board,
				   int				npos)
{
  int			i;
  int			nb_pixel;
  int			side_size;

  side_size = unit->area.w / 2;
  if (env->pixels[npos] != AIR)
    nb_pixel += 1;
  i = 1;
  while (i <= side_size)
    {
      if (board[npos + i] != AIR)
	nb_pixel += 1;
      if (board[npos - i] != AIR)
	nb_pixel += 1;
      i += 1;
    }
  if (nb_pixel >= MIN_PIXEL_TO_HOLD)
    {
      unit->area.y += 1;
      return (true);
    }
  return (false);
}

static int		check_remaining_front(t_unit		*unit,
					      unsigned int	*board,
					      int		npos,
					      int		i)
{
  while (i < unit->area.h && board[npos - (env->clipable.buffer.width * i)] != AIR)
    i += 1;
  if (i == unit->area.h)
    return(1);
  return(0);
}

static void		move_toward(t_unit			*unit,
				    t_bunny_accurate_position	target_pos,
				    t_bunny_pixelarray		*env,
				    int				npos)
{
  int			direction;
  int			max_climbing_height;
  unsigned int		*board;
  int			i;

  board = (unsigned int *)env->pixels;
  direction = (unit->area.x < target_pos.x) ? 1 : -1;
  // + 1 pour passer l'origine + 1 pour check devant le personnage
  if (direction == 1)
      npos += (unit->area.w / 2) + 2;
  else
    npos -= (unit->area.w / 2) + 2;
  max_climbing_height = unit->area.h / COEF_CLIMBING_HEIGHT;
  i = 0;
  while (i < max_climbing_height && board[npos - (env->clipable.buffer.width * i)] != AIR)
    i += 1;
  if (i < max_climbing_height)
    {
      unit->area.x += check_remaining_front(unit, board, npos, i);
      unit->area.y -= i;
    }
}

void			pixel_move(t_unit			*unit,
				   t_bunny_accurate_position	target_pos,
				   t_bunny_pixelarray		*env)
{
  int			npos;
  int			side;
  unsigned int		*board;

  board = (unsigned int *)env->pixels;
  // + 1 pour check sous le personnage
  npos = (unit->area.y + 1) * env->clipable.buffer.width + unit->area.x;
  if (check_fall(unit, target_pos, board, npos))
    return;
  if (unit->area.x == target_pos.x)
    return;
  move_toward(unit, target_pos, board, npos);
}
