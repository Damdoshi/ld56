#include		"program.h"


void			ingame_specter_action(t_ingame	*ingame,
					      t_unit	*unit)
{
  (void)ingame;
  if (bunny_sprite_animation_name("Idle") == bunny_sprite_get_animation(unit->sprite))
    {
      /*
	double tmp = unit->sprite->clipable.color_mask.argb[3];
	
	tmp = bunny_clamp(tmp + 255.0 / (bunny_get_frequency() / 2.0), 0, 255);
	if ((unit->sprite->clipable.color_mask.argb[3] = tmp) == 255)
      */
      if (bunny_sprite_is_still(unit->sprite))
	bunny_sprite_set_animation_name(unit->sprite, "Attack");
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

      if (ratio >= 0.75)
	{
	  ratio = ratio - 0.75;
	  ratio = ratio / 0.75;
	  ratio = 1 - ratio;
	  unit->sprite->clipable.color_mask.argb[3] = efget_value(ratio, 0, 255);
	}
      double delay = 0.5;

      unit->area.x += (unit->target.x - unit->spawn.x) / (bunny_get_frequency() * delay);
      unit->area.y += (unit->target.y - unit->spawn.y) / (bunny_get_frequency() * delay);
    }

  if (bunny_rectangular_collision(&unit->area, &ingame->player->area))
    {
      ingame_get_hurt(ingame, ingame->player, 0.2);
      ingame_delete_unit(ingame, unit);
    }
}


