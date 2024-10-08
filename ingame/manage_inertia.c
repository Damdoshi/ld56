#include		"program.h"

static void		moderate_forces(t_ingame	*ing,
					t_unit		*unit)
{
  if (unit->inertia.y > 0)
    unit->inertia.y = bunny_clamp(unit->inertia.y * 1.001, -13, +13);
  else
    unit->inertia.y = bunny_clamp(unit->inertia.y * 0.999, -13, +13);

  if (fabs(unit->inertia.x) > 0.01)
    {
      if (ingame_bottom_collision(ing, unit, false) &&
	  bunny_sprite_animation_name("Crashing") != bunny_sprite_get_animation(unit->sprite))
	unit->inertia.x *= 0.75;
      else
	unit->inertia.x *= 0.95;
    }
  else
    unit->inertia.x = 0;
}

static void		check_bottom(t_ingame		*ingame,
				     t_unit		*unit)
{
  for (int n_move = 0; n_move < unit->inertia.y; ++n_move)
    {
      if (ingame_bottom_collision(ingame, unit, false))
	{
	  if (unit->inertia.y > 8.75)
	    {
	      bunny_sprite_set_animation_name(unit->sprite, "Crashing");
	      ingame_get_hurt(ingame, unit, (unit->inertia.y - 8) / 4.0);
	    }
	  else if (unit->inertia.y > 8)
	    ingame_get_hurt(ingame, unit, (unit->inertia.y - 8) / 4.0);
	  else if (unit->inertia.y > 5)
	    {
	      bunny_sound_play(&(ingame->sfx[PLAYER][19]->sound));
	      if (unit->hurt[0])
		bunny_sound_play(&unit->hurt[0]->sound);
	    }
	  else if (unit->inertia.y > 1)
	    if (!ingame_bottom_collision(ingame, unit, true))
	      bunny_sound_play(&(ingame->sfx[PLAYER][18]->sound));
	  unit->inertia.y = 0;
	  return ;
	}
      unit->area.y += 1;
      n_move += 1;
    }
}

static void		check_top(t_ingame		*ingame,
				  t_unit		*unit)
{
  for (int n_move = 0; n_move < -unit->inertia.y; ++n_move)
    {
      if (ingame_top_collision(ingame, unit))
	{
	  unit->inertia.y = 0;
	  return ;
	}
      unit->area.y -= 1;
      n_move += 1;
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
  int			step_height;
  int			max_step_height;

  n_move = 0;
  step_height = 0;
  max_step_height = unit->stair;
  side_size = unit->area.w / 2;
  x = unit->area.x + (side_size + 2) * side;
  while (n_move < unit->inertia.x * side)
    {
      i = 0;
      while (i < unit->area.h)
	{
	  if (!ingame_traversable(ingame, x, unit->area.y - i))
	    {
	      step_height += 1;
	      if (step_height > max_step_height)
		return;
	    }
	  i += 1;
	}
      i = 0;
      while (i < step_height)
	{
	  if (ingame_top_collision(ingame, unit))
	    return;
	  unit->area.y -= 1;
	  unit->inertia.x *= 0.6;
	  unit->inertia.y = 0;
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
  if (unit->inertia.y > 0)
    check_bottom(ingame, unit);
  else if (unit->inertia.y < 0)
    check_top(ingame, unit);

  if (unit->inertia.x < 0)
    check_side(ingame, -1, unit);
  else if (unit->inertia.x > 0)
    check_side(ingame, 1, unit);
}
