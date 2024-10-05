// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"

double				afabs(double			x)
{
  return (x < 0 ? x : -x);
}

t_bunny_response		ingame_key(t_bunny_event_state	state,
					    t_bunny_keysym	sym,
					    t_ingame		*ingame)
{
  t_bunny_accurate_position	target_pos;

  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_1)
    {
      ingame->cursor_type = SELECTION;
      bunny_sprite_set_animation_name(ingame->cursor, "Selection");
      return (GO_ON);
    }
  if (sym == BKS_2)
    {
      ingame->cursor_type = ATTACK;
      bunny_sprite_set_animation_name(ingame->cursor, "Attack");
      return (GO_ON);
    }
  if (sym == BKS_3)
    {
      ingame->cursor_type = CONSTRUCTION;
      bunny_sprite_set_animation_name(ingame->cursor, "Construction");
      return (GO_ON);
    }


  if (sym >= BKS_F1 && sym <= BKS_F4)
    {
      ingame_get_hurt(ingame, 0.1 * (sym - BKS_F1 + 1));
      return (GO_ON);
    }


  //// DEBUG
  
  if (sym == BKS_Z)
    {
      target_pos.x = ingame->player->area.x;
      target_pos.y = ingame->player->area.y - 10;
      for (int i = 0; i < 10; i += 1)
	pixel_move(ingame, ingame->player, target_pos);
      printf("Player pos : x: %f y: %f\n", ingame->player->area.x, ingame->player->area.y);
    }

  if (sym == BKS_S)
    {
      target_pos.x = ingame->player->area.x;
      target_pos.y = ingame->player->area.y + 10;
      for (int i = 0; i < 10; i += 1)
	pixel_move(ingame, ingame->player, target_pos);
      printf("Player pos : x: %f y: %f\n", ingame->player->area.x, ingame->player->area.y);
    }

  if (sym == BKS_Q)
    {      
      target_pos.x = ingame->player->area.x - 10;
      target_pos.y = ingame->player->area.y;
      for (int i = 0; i < 10; i += 1)
	pixel_move(ingame, ingame->player, target_pos);
      printf("Player pos : x: %f y: %f\n", ingame->player->area.x, ingame->player->area.y);
    }
  
  if (sym == BKS_D)
    {
      target_pos.x = ingame->player->area.x + 10;
      target_pos.y = ingame->player->area.y;
      for (int i = 0; i < 10; i += 1)
	pixel_move(ingame, ingame->player, target_pos);
      printf("Player pos : x: %f y: %f\n", ingame->player->area.x, ingame->player->area.y);
    }  

  /*
  if (sym == BKS_LEFT)
    {
      if (state == GO_DOWN)
	{
	  bunny_sprite_set_animation_name(ingame->mmx, "StartRunning");
	  ingame->mmx->clipable.scale.x = afabs(ingame->mmx->clipable.scale.x);
	}
      else
	bunny_sprite_set_animation_name(ingame->mmx, "Idle");
    }
  if (sym == BKS_RIGHT)
    {
      if (state == GO_DOWN)
	{
	  bunny_sprite_set_animation_name(ingame->mmx, "StartRunning");
	  ingame->mmx->clipable.scale.x = fabs(ingame->mmx->clipable.scale.x);
	}
      else
	bunny_sprite_set_animation_name(ingame->mmx, "Idle");
    }
  */
  return (GO_ON);
}
