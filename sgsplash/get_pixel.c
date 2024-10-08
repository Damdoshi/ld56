#include	"sgsplash.h"

unsigned int     get_pixel(const t_bunny_pixelarray *px,
                           t_bunny_position         pos)
{
    return (((uint32_t*)px->pixels)[(pos.x) + (pos.y * px->clipable.buffer.width)]);
}
