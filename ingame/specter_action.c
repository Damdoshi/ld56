#include		"program.h"


void			ingame_specter_action(t_ingame	*ingame,
					      t_unit	*unit)
{
  double		x;
  double		y;

  if (unit->sprite->clipable.color_mask.argb[3] < 255 && unit->disp == false)
    {
      double tmp = unit->sprite->clipable.color_mask.argb[3];

      tmp = bunny_clamp(tmp + 255.0 / bunny_get_frequency(), 0, 255);
      unit->sprite->clipable.color_mask.argb[3] = tmp;
    }
  else
    {
      double dist;
      double ratio;

      dist = distance(unit->area.x, unit->area.y, unit->target.x, unit->target.y);
      if ((ratio = (dist * dist) / (200.0 * 200)) > 1)
	ratio = 1;
      ratio = 1 - ratio;
      unit->disp = true;

      printf("%f\n", ratio);

      if (ratio >= 0.5)
	{
	  ratio = ratio - 0.5;
	  ratio = ratio / 0.5;
	  ratio = 1 - ratio;
	  unit->sprite->clipable.color_mask.argb[3] = efget_value(ratio, 0, 255);
	}

      unit->area.x += (unit->target.x - unit->spawn.x) / bunny_get_frequency();
      unit->area.y += (unit->target.y - unit->spawn.y) / bunny_get_frequency();
    }
}


