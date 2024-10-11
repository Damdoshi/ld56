
#include		"program.h"

void			ingame_display_mouse(t_ingame		*ingame)
{
  t_bunny_position	pos;

  if (bunny_sprite_animation_name("Attack") == bunny_sprite_get_animation(ingame->player->sprite))
    return ;
  if (bunny_sprite_animation_name("Unattack") == bunny_sprite_get_animation(ingame->player->sprite))
    return ;

  pos = get_real_mouse_position(ingame->program->screen);
  bunny_blit(&ingame->program->screen->buffer, &ingame->cursor->clipable, &pos);
}
