// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"ingame.h"
#include		"movement.h"

t_bunny_response	ingame_loop(t_ingame		*ingame)
{
  size_t		i;
  t_bunny_accurate_position	target_pos;

  /// TRUCS DE JOUEUR
  
  target_pos.x = ingame->player.area.x;
  target_pos.y = ingame->player.area.y;
  pixel_move(&ingame->player, target_pos, ingame->map);

  ingame->camera.x = ingame->player.area.x - ingame->program->screen->buffer.width / 2;
  ingame->camera.y = ingame->player.area.y - ingame->program->screen->buffer.height / 2;

  ingame->layer[1]->clipable.clip_x_position = ingame->camera.x;
  ingame->layer[1]->clipable.clip_y_position = ingame->camera.y;
  ingame->layer[1]->clipable.clip_width = ingame->layer[1]->clipable.buffer.width;
  ingame->layer[1]->clipable.clip_height = ingame->layer[1]->clipable.buffer.height;

  if (ingame->layer[1]->clipable.clip_x_position < 0)
    {
      ingame->layer[1]->clipable.clip_width += ingame->layer[1]->clipable.clip_x_position;
      ingame->layer[1]->clipable.clip_x_position *= -1;
    }
  if (ingame->layer[1]->clipable.clip_y_position < 0)
    {
      ingame->layer[1]->clipable.clip_height += ingame->layer[1]->clipable.clip_y_position;
      ingame->layer[1]->clipable.clip_y_position *= -1;
    }

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

