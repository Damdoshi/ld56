/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2016
**
** TekFunction
*/

#include		"tekfunction.h"

void			tekinit(void)
{
  bunny_enable_full_blit(true);
  gl_bunny_my_set_pixel = tekpixel;
  gl_bunny_my_set_line = tekline;
  gl_bunny_my_fill = tekfill;
  gl_bunny_my_blit = tekblit;
  gl_bunny_my_clear = tekclear;
}

