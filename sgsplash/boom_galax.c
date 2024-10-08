#include			"sgsplash.h"

void				boom_galax(t_sgsplash			*spa)
{
  t_bunny_position pos;
  t_bunny_color col;
  double v = 20.5;
  for (uint32_t i = 0; i < (spa->pix->clipable.buffer.width * spa->pix->clipable.buffer.height) - 1; i++)
    {
      if (spa->pts[i].x < 0)
	spa->pts[i].x -= v - (spa->pts[i].x / 5) - rand() % 50;
      else
	spa->pts[i].x += v + (spa->pts[i].x / 5) + rand() % 50;
      pos.x = spa->pts[i].x + spa->pos.x;
      pos.y = spa->pts[i].y + spa->pos.y;
      col.full = spa->col[i];
      tset_pixel(spa->pix, pos, col);
      v -= 0.000001;
    }
}
