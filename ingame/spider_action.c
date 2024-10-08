
#include		"program.h"

void			ingame_spider_action(t_ingame	*ingame,
					     t_unit	*unit)
{
  int			max = 0;
  
  // Dans tous les cas on mange le pixel en dessous
  if (unit->type == EATSPIDER)
    {
      if (bunny_sprite_animation_name("Idle") != bunny_sprite_get_animation(unit->sprite))
	return ;
      for (int j = -50; j < unit->area.h + 20; ++j)
	{
	  for (int i = -20; i < unit->area.w + 20; ++i)
	    {
	      int x = i + unit->area.x;
	      int y = j + unit->area.y;

	      if (unit->health <= 0)
		return ;
	      if (BITGET(ingame->attack_map, x, y, ingame->map_size.x))
		{
		  t_bunny_position pos = {x, y};

		  if ((max += 1) > 5)
		    return ;
		  unit->health -= 0.001;
		  bunny_sprite_set_animation_name(unit->sprite, "Dig");
		  ingame_pixel_delete(ingame, pos);
		  break ;
		}
	    }
	}
    }
  else if (unit->type == WALLSPIDER)
    {
      if (bunny_sprite_animation_name("Idle") != bunny_sprite_get_animation(unit->sprite))
	return ;
      for (int j = 0; j < unit->area.h + 10; ++j)
	for (int i = -20; i < unit->area.w + 20; ++i)
	  {
	    int x = i + unit->area.x;
	    int y = j + unit->area.y;
	    
	    if (BITGET(ingame->build_map, x, y, ingame->map_size.x))
	      {
		t_bunny_position pos = {x, y};
		unit->health -= 0.001;
		bunny_sprite_set_animation_name(unit->sprite, "Dig");
		ingame_pixel_build(ingame, pos);
	      }
	    if (unit->health <= 0)
	      return ;
	  }
    }
  
  // On est plus en déplacement
  if (fabs(unit->area.x - unit->target.x) < 2)
    {
      unit->area.x = unit->target.x;

      // On se met en recherche de bouffe
      if (unit->type == EATSPIDER)
	ingame_attack_map(ingame, unit, 200);
      if (unit->type == WALLSPIDER)
	ingame_build_map(ingame, unit, 200);
      return ;
    }


  // On est en déplacement
  if (unit->area.x > unit->target.x)
    ingame_go(ingame, unit, -1);
  else if (unit->area.x < unit->target.x)
    ingame_go(ingame, unit, 1);
}
