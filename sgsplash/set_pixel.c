#include		"sgsplash.h"

void                    efset_pixel(t_bunny_pixelarray              *px,
				    t_bunny_position                pos,
				    unsigned int                    color)
{
  if (pos.x > 0
      && pos.y > 0
      && pos.x < px->clipable.buffer.width
      && pos.y < px->clipable.buffer.height)
    ((int*)px->pixels)[(pos.x) + (pos.y * px->clipable.buffer.width)] = color;
}
