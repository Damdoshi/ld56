
#include	"program.h"

int		ingame_side_collision(t_ingame	*ing,
				      t_unit	*unit,
				      int	side)
{
  int		max_step_height = unit->stair;
  int		step_height = 0;
  int		side_size = unit->area.w / 2;
  int		x = unit->area.x + (side_size + 2) * side;

  for (int i = 0; i < unit->area.h; ++i)
    if (!ingame_traversable(ing, x, unit->area.y - i))
      {
	step_height += 1;
	if (step_height > max_step_height)
	  return (-1);
      }
  return (step_height);
}

