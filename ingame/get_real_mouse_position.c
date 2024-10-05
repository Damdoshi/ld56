
#include			"program.h"

t_bunny_position		ingame_get_real_mouse_position(t_ingame		*ing)
{
  t_bunny_accurate_position	pos = {
    bunny_get_mouse_position()->x,
    bunny_get_mouse_position()->y
  };
  t_bunny_accurate_area		top_left = {
    ing->program->screen->position.x,
    ing->program->screen->position.y,
    ing->program->screen->buffer.width * ing->program->screen->scale.x,
    ing->program->screen->buffer.height * ing->program->screen->scale.y
  };
  t_bunny_position		final;
  
  if (pos.x < top_left.x)
    final.x = 0;
  if (pos.x > top_left.x + top_left.w)
    final.x = ing->program->screen->buffer.width;
  if (pos.y < top_left.y)
    final.y = 0;
  if (pos.y > top_left.y + top_left.h)
    final.y = ing->program->screen->buffer.height;

  final.x = ((pos.x - top_left.x) / top_left.w) * ing->program->screen->buffer.width;
  final.y = ((pos.y - top_left.y) / top_left.h) * ing->program->screen->buffer.height;
  return (final);
}
