#include		"sgsplash.h"

void                    efclear_pixelarray(t_bunny_pixelarray               *picture,
					   unsigned int                     color)
{
    int i;

    i = 0;
    while (i < ((picture -> clipable.buffer.width) * (picture -> clipable.buffer.height)))
        {
            ((int*)picture->pixels)[i] = color;
            i ++;
        }
}
