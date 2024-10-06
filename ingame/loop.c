// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"

static void		check_actions(t_ingame	*ingame)
{
  const bool		*keys = bunny_get_keyboard();

  if (keys[BKS_Z] || keys[BKS_W] || keys[BKS_SPACE])
    {
      if (ingame->player->inertia.y < 0.5 && ingame->player->inertia.y > -0.5)
	ingame->player->inertia.y = -100;
    }
  if (keys[BKS_S])
    {
      if (ingame->player->inertia.y < 0.5 && ingame->player->inertia.y > -0.5)
	ingame->player->inertia.y = 0.5;
      else if (ingame->player->inertia.y < -0.5)
	ingame->player->inertia.y *= 0.25;
      else
	ingame->player->inertia.y *= 1.05;
    }

  if (keys[BKS_Q] || keys[BKS_A])
    {
      if (ingame->player->inertia.x < 0.5 && ingame->player->inertia.x > -0.5)
	ingame->player->inertia.x = -0.5;
      else if (ingame->player->inertia.x > 0.5)
	ingame->player->inertia.x *= 0.25;
      else
	ingame->player->inertia.x *= 1.05;
    }
  if (keys[BKS_D])
  {
    if (ingame->player->inertia.x < 0.5 && ingame->player->inertia.x > -0.5)
      ingame->player->inertia.x = 0.5;
    else if (ingame->player->inertia.x < -0.5)
      ingame->player->inertia.x *= 0.25;
    else
      ingame->player->inertia.x *= 1.05;
  }
  printf("inertie x %f y %f\n", ingame->player->inertia.x, ingame->player->inertia.y);
}

t_bunny_response	ingame_loop(t_ingame		*ingame)
{

  /// TRUCS DE JOUEUR

  check_actions(ingame);
  manage_inertia(ingame, ingame->player);
  
  ingame->camera.x = ingame->player->area.x - ingame->program->screen->buffer.width / 2;
  ingame->camera.y = ingame->player->area.y - ingame->program->screen->buffer.height / 2;

  /*
  ingame->layer[1]->clipable.clip_x_position = ingame->camera.x;
  ingame->layer[1]->clipable.clip_y_position = ingame->camera.y;
  ingame->layer[1]->clipable.clip_width = ingame->layer[1]->clipable.buffer.width;
  ingame->layer[1]->clipable.clip_height = ingame->layer[1]->clipable.buffer.height;

  if (ingame->layer[1]->clipable.clip_x_position < 0)
    {
      ingame->layer[1]->clipable.clip_width += ingame->layer[1]->clipable.clip_x_position;
      ingame->layer[1]->clipable.clip_x_position = 0;
    }
  if (ingame->layer[1]->clipable.clip_y_position < 0)
    {
      ingame->layer[1]->clipable.clip_height += ingame->layer[1]->clipable.clip_y_position;
      ingame->layer[1]->clipable.clip_y_position = 0;
    }
  */

  /// MISC

  ingame->frame_counter +=1;
  if (ingame_progress_health(ingame) == false)
    {
      if (ingame->life-- > 0)
	return (SWITCH_CONTEXT);
      ingame->program->context = CINEMATIC;
      ingame->program->cinematic.following_context = MAIN_MENU;
      return (SWITCH_CONTEXT);
    }
  for (size_t i = 0; i < ingame->last_sprite; ++i)
    bunny_sprite_animate_now(ingame->sprites[i]);
  ingame_event(ingame);
  return (GO_ON);
}

