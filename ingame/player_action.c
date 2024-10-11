
#include		"program.h"

void			ingame_player_action(t_ingame	*ingame,
					     t_unit	*unit)
{
  const bool		*keys = bunny_get_keyboard();
  int			x = 0;

  if (ingame->enlighted == false && ingame->last_enlightnment < bunny_get_current_time() - 5)
    {
      double		ang = (rand() % (int)(200000 * M_PI)) / 100000.0;
      t_bunny_position	pos = {
	cos(ang) * 100 + unit->area.x,
	sin(ang) * 100 + unit->area.y - unit->area.h / 2,
      };
      int		id;

      id = ingame_new_unit(ingame, SPECTER, pos);
      double x = ingame->player->area.x - unit->spawn.x;
      double y = (ingame->player->area.y - ingame->player->area.h / 2) - unit->spawn.y;

      unit[id].ang = atan2(y, x);
      unit[id].sprite->clipable.rotation = 180.0 * unit[id].ang / M_PI + 90;
      ingame->units[id].target.x = cos(unit[id].ang + M_PI) * 100 + unit[id].area.x;
      ingame->units[id].target.y = sin(unit[id].ang + M_PI) * 100 + unit[id].area.y;
      ingame->units[id].sprite->clipable.color_mask.argb[3] = 0;
      ingame->last_enlightnment += 5;
    }

  if (bunny_sprite_animation_name("Crashing") == bunny_sprite_get_animation(unit->sprite))
    {
      if (bunny_sprite_is_still(unit->sprite) &&
	  unit->health > 0 && ingame_bottom_collision(ingame, unit, false))
	bunny_sprite_set_animation_name(unit->sprite, "GettingUp");
      return ;
    }  
  if (bunny_sprite_animation_name("GettingUp") == bunny_sprite_get_animation(unit->sprite))
    return ;
  if (bunny_sprite_animation_name("Unattack") == bunny_sprite_get_animation(unit->sprite))
    return ;

  if (bunny_sprite_animation_name("Attack") == bunny_sprite_get_animation(unit->sprite))
    {
      if (!keys[BKS_RSHIFT])
	bunny_sprite_set_animation(unit->sprite, "Unattack");
      return ;
    }
  if (keys[BKS_RSHIFT] && ingame_bottom_collision(ingame, unit, false))
    {
      bunny_sprite_set_animation(unit->sprite, "Attack");
      return ;
    }
  
  if (keys[BKS_Q] || keys[BKS_A] || keys[BKS_LEFT])
    x = -1;
  if (keys[BKS_D] || keys[BKS_RIGHT])
    x += 1;
	   if (keys[BKS_LSHIFT])
    x *= 2;
  if (x)
    ingame_go(ingame, unit, x);

  if (ingame_bottom_collision(ingame, unit, true))
    {
      if (x || fabs(unit->inertia.x) > 0.1)
	{
	  bunny_sprite_set_animation_name(unit->sprite, "Walking");
	  if(ingame->step_frame <= ingame->frame_counter)
	    {
	      bunny_sound_play(&(ingame->sfx[PLAYER][11 + rand() % 5]->sound));
	      ingame->step_frame = ingame->frame_counter + 20;
	    }
	}
      else
	bunny_sprite_set_animation_name(unit->sprite, "Idle");
    }
  else
    {
      if (unit->inertia.y < 0)
	bunny_sprite_set_animation_name(unit->sprite, "Jumping");
      else if (unit->inertia.y > 1 && unit->inertia.y < 4)
	bunny_sprite_set_animation_name(unit->sprite, "Landing");
      else if (unit->inertia.y > 0)
	bunny_sprite_set_animation_name(unit->sprite, "Falling");
    }

  // Tricheur!
  if (keys[BKS_F12])
    {
      if (keys[BKS_UP])
	unit->area.y -= 10;
      if (keys[BKS_DOWN])
	unit->area.y += 10;
      if (keys[BKS_LEFT])
	unit->area.x -= 10;
      if (keys[BKS_RIGHT])
	unit->area.x += 10;
      unit->inertia.x = 0;
      unit->inertia.y = 0;
    }
}
