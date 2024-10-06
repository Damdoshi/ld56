
#include			"program.h"

t_bunny_position		get_real_mouse_position(t_bunny_picture	*screen)
{
  t_bunny_accurate_position	pos = {
    bunny_get_mouse_position()->x,
    bunny_get_mouse_position()->y
  };
  int				rx = screen->buffer.width * screen->scale.x;
  int				ry = screen->buffer.height * screen->scale.y;
  t_bunny_accurate_area		top_left = {
    screen->position.x - rx / 2.0,
    screen->position.y - ry / 2.0,
    screen->buffer.width * screen->scale.x,
    screen->buffer.height * screen->scale.y
  };
  t_bunny_position		final;

  if (pos.x < top_left.x)
    final.x = 0;
  if (pos.x > top_left.x + top_left.w)
    final.x = screen->buffer.width;
  if (pos.y < top_left.y)
    final.y = 0;
  if (pos.y > top_left.y + top_left.h)
    final.y = screen->buffer.height;

  final.x = ((pos.x - top_left.x) / top_left.w) * screen->buffer.width;
  final.y = ((pos.y - top_left.y) / top_left.h) * screen->buffer.height;
  return (final);
}
