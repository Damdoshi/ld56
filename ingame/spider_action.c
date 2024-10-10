
#include		"program.h"

void			ingame_spider_action(t_ingame	*ingame,
					     t_unit	*unit)
{
  t_bunny_bitfield	*bf = ingame->water_map[ingame->current_water_map];
  int			max = 0;
  bool			attack = false;

  if (BITGET(bf, unit->area.x, unit->area.y, ingame->map_size.x))
    unit->health -= 0.05;
  
  if (bunny_sprite_animation_name("Idle") != bunny_sprite_get_animation(unit->sprite))
    return ;

  // Dans tous les cas on mange le pixel en dessous
  if (unit->type == EATSPIDER)
    {
      // Attaque des bad spiders - prioritaire
      for (size_t i = 0; i < ingame->last_unit; ++i)
	if (ingame->units[i].type == BADSPIDER && ingame->units[i].health > 0 &&
	    distance(unit->area.x, unit->area.y,
		     ingame->units[i].area.x, ingame->units[i].area.y
		     ) < 200 * 200)
	  {
	    attack = true;
	    unit->target.x = ingame->units[i].area.x + unit->area.w / 2;
	    unit->target.y = ingame->units[i].area.y;
	    if (bunny_rectangular_collision(&unit->area, &ingame->units[i].area))
	      {
		bunny_sprite_set_animation_name(unit->sprite, "Dig");
		ingame_get_hurt(ingame, &ingame->units[i], 0.20);
		if (unit->area.x < ingame->units[i].area.x)
		  ingame->units[i].inertia.x = 2;
		if (unit->area.x > ingame->player->area.x)
		  ingame->units[i].inertia.x = -2;
	      }
	  }

      if (attack == false)
	{
	  // Bouffage de la terre
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

		      if ((max += 1) > 20)
			return ;
		      unit->health -= 0.001;
		      bunny_sprite_set_animation_name(unit->sprite, "Dig");
		      ingame_pixel_delete(ingame, pos, 1);
		      break ;
		    }
		}
	    }
	}
    }
  else if (unit->type == WALLSPIDER)
    {
      for (int j = -20; j < unit->area.h + 20; ++j)
	for (int i = -40; i < unit->area.w + 40; ++i)
	  {
	    int x = i + unit->area.x;
	    int y = j + unit->area.y;
	    
	    if (BITGET(ingame->build_map, x, y, ingame->map_size.x))
	      {
		t_bunny_position pos = {x, y};

		if ((max += 1) > 20)
		  return ;
		unit->health -= 0.001;
		bunny_sprite_set_animation_name(unit->sprite, "Dig");
		ingame_pixel_build(ingame, pos);
	      }
	    if (unit->health <= 0)
	      return ;
	  }
    }
  else if (unit->type == BADSPIDER)
    {
      for (size_t i = 0; i < ingame->last_unit; ++i)
	if (ingame->units[i].type != HERO && ingame->units[i].type != LIGHTSPIDER)
	  continue ;
	else if (distance(ingame->units[i].area.x, ingame->units[i].area.y,
			  unit->area.x, unit->area.y) < 100 * 100)
	  {
	    unit->target.x = ingame->units[i].area.x + unit->area.w / 2;
	    unit->target.y = ingame->units[i].area.y;
	    if (bunny_rectangular_collision(&unit->area, &ingame->units[i].area))
	      {
		bunny_sprite_set_animation_name(unit->sprite, "Dig");
		ingame_get_hurt(ingame, &ingame->units[i], 0.05);
		if (unit->area.x < ingame->units[i].area.x)
		  ingame->units[i].inertia.x = 2;
		if (unit->area.x > ingame->units[i].area.x)
		  ingame->units[i].inertia.x = -2;
	      }
	  }
    }
  
  // On est plus en déplacement
  if (fabs(unit->area.x - unit->target.x) < 2)
    {
      unit->area.x = unit->target.x;

      // On se met en recherche de bouffe
      if (unit->type == EATSPIDER)
	ingame_move_map(ingame, ingame->attack_map, unit, 200);
      if (unit->type == WALLSPIDER)
	ingame_move_map(ingame, ingame->build_map, unit, 200);
      return ;
    }

  // On est en déplacement
  if (unit->area.x > unit->target.x)
    ingame_go(ingame, unit, -1);
  else if (unit->area.x < unit->target.x)
    ingame_go(ingame, unit, 1);
}
