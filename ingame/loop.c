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
  int			x = 0;
  
  if (keys[BKS_Q] || keys[BKS_A] || keys[BKS_LEFT])
    x = -1;
  if (keys[BKS_D] || keys[BKS_RIGHT])
    x += 1;
  ingame_go(ingame, ingame->player, x);
}

t_bunny_response	ingame_loop(t_ingame		*ingame)
{
  check_actions(ingame);
  for (size_t i = 1; i < ingame->last_unit; ++i)
    {
      ingame->units[i].inertia.y += 0.2;
      manage_inertia(ingame, &ingame->units[i]);
    }
  
  ingame->camera.x = ingame->player->area.x - ingame->program->screen->buffer.width / 2;
  ingame->camera.y = ingame->player->area.y - ingame->program->screen->buffer.height / 2;
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

