// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"

t_bunny_response	ingame_loop(t_ingame		*ingame)
{
  t_bunny_bitfield	*target = NULL;

  ingame_water(ingame);
  
  // Brush d'action
  if (ingame->cursor_type == ATTACK)
    target = ingame->attack_map;
  else if (ingame->cursor_type == CONSTRUCTION)
    target = ingame->build_map;
  if (target)
    {
      if (bunny_get_mouse_button()[BMB_LEFT])
	ingame_brush(ingame, target, true, ingame->cursor_type);
      if (bunny_get_mouse_button()[BMB_RIGHT])
	ingame_brush(ingame, target, false, ingame->cursor_type);
    }
  
  // Action des unités
  for (size_t i = 0; i < ingame->last_unit; ++i)
    {
      ingame->units[i].inertia.y += 0.2;
      if (ingame->units[i].health <= 0)
	{
	  ingame_unselect_unit(ingame, &ingame->units[i]);
	  bunny_sprite_set_animation_name(ingame->units[i].sprite, "Die");
	  if (ingame->units[i].light_radius > 0)
	    ingame->units[i].light_radius *= 0.95;
	  if (bunny_sprite_is_still(ingame->units[i].sprite) && 0)
	    {
	      ingame_delete_unit(ingame, &ingame->units[i]);
	      i -= 1;
	    }
	}
      else
	ingame->units[i].action(ingame, &ingame->units[i]);
      manage_inertia(ingame, &ingame->units[i]);
    }

  // Position de la caméra
  ingame->camera.x = ingame->player->area.x - ingame->program->screen->buffer.width / 2;
  ingame->camera.y = ingame->player->area.y - ingame->program->screen->buffer.height / 2;
  if (ingame_get_pixel(ingame, ingame->player->area.x, ingame->player->area.y) == VICTORY)
    {
      ingame->current_level += 1;
      return (SWITCH_CONTEXT);
    }

  /// Divers
  ingame->frame_counter +=1;
  if (ingame_progress_health(ingame) == false)
    {
      if (ingame->life-- > 0)
	ingame_add_event(ingame, ingame->frame_counter + bunny_get_frequency(), RETRY);
      else
	ingame_add_event(ingame, ingame->frame_counter + bunny_get_frequency(), GAME_OVER);	
    }
  for (size_t i = 0; i < ingame->last_sprite; ++i)
    bunny_sprite_animate_now(ingame->sprites[i]);
  return (ingame_event(ingame));
}

 
