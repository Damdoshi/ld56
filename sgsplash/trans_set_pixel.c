#include		"sgsplash.h"

static unsigned char    efcolor_ratio(unsigned char                  top,
                                      unsigned char                  bottom,
                                      unsigned char                  transparency)
{
    if (transparency == 0)
        return (bottom);
    if (transparency == 255)
        return (top);
    else
        {
            double      ratio;

            ratio = (double)transparency / 255;
            return ((double)efget_value(ratio,(double)bottom,(double)top));
        }
}

static unsigned int     efget_pixel(const t_bunny_pixelarray        *px,
                                    t_bunny_position                pos)
{
    return (((int*)px->pixels)[(pos.x) + (pos.y * px->clipable.buffer.width)]);
}

void                    tset_pixel(const t_bunny_pixelarray		*picture,
				   t_bunny_position			pos,
				   t_bunny_color			color)
{
    t_bunny_color       new_color;
    t_bunny_color       col;

    if (pos.x > picture->clipable.buffer.width
        || pos.y > picture->clipable.buffer.height
        || pos.x < 0
        || pos.y < 0)
        return ;
    col.full = efget_pixel(picture, pos);
    new_color.argb[0] = efcolor_ratio(color.argb[0], col.argb[0], color.argb[3]);
    new_color.argb[1] = efcolor_ratio(color.argb[1], col.argb[1], color.argb[3]);
    new_color.argb[2] = efcolor_ratio(color.argb[2], col.argb[2], color.argb[3]);
    new_color.argb[3] = col.argb[3];
    ((int*)picture->pixels)[(pos.x) + (pos.y * picture -> clipable.buffer.width)] = new_color.full;
}
