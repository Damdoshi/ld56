#include			"sgsplash.h"

void				app_nom(t_sgsplash			*spa,
					double				ratio)
{
  t_bunny_position	pos;

  ratio -= 0.5;
  if (ratio > 0.40)
    {
      if ((ratio = (ratio - 0.40) / 0.10) >=1)
	ratio = 1;
      ratio = 1 - ratio;
      spa->font->clipable.color_mask.argb[ALPHA_CMP] = 255 * ratio;
    }
  else
    {
      if ((ratio = ratio / 0.4) >= 1)
	ratio = 1;
      spa->font->clipable.color_mask.argb[ALPHA_CMP] = 255 * ratio;
    }
  spa->font->offset.x = 0;
  pos.x = (spa->pix->clipable.buffer.width / 2) - 64 * 3;
  spa->font->offset.y = 0;
  pos.y = (spa->pix->clipable.buffer.height / 2) - 32;
  bunny_clear(&spa->font->clipable.buffer, 0);
  bunny_draw(&spa->font->clipable);
  bunny_blit(&spa->win->buffer, &spa->font->clipable, &pos);
}
