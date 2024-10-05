/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2016
**
** TekFunction
*/

#include		"tekfunction.h"

void			tekletter(t_bunny_pixelarray			*font,
				  char					c)
{
  font->clipable.clip_width = 5;
  font->clipable.clip_height = 7;
  font->clipable.clip_x_position = c * font->clipable.clip_width;
  font->clipable.clip_y_position = 0;
}

void			tektext(t_bunny_pixelarray			*out,
				t_bunny_pixelarray			*font,
				const t_bunny_position			*pos,
				const char				*str)
{
  t_bunny_position	cursor;
  size_t		i;

  tekletter(font, 0);
  for (i = 0, cursor.x = pos->x, cursor.y = pos->y; str[i] != '\0'; ++i)
    if (str[i] == '\n')
      {
	cursor.x = pos->x;
	cursor.y += font->clipable.clip_height + 1;
      }
    else
      {
	tekletter(font, str[i]);
	tekblit(out, font, &cursor);
	cursor.x += font->clipable.clip_width + 1;
      }  
}
