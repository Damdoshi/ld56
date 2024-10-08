
#include		"program.h"

void			ingame_display_order_areas(t_ingame		*ingame)
{
  bunny_clear(&ingame->action_screen->clipable.buffer, 0);
  for (int j = 0; j < ingame->program->screen->buffer.height; ++j)
    for (int i = 0; i < ingame->program->screen->buffer.width; ++i)
      {
	int jj = j + ingame->camera.y;
	int ii = i + ingame->camera.x;

	if (jj < 0 || ii < 0 || jj >= ingame->map_size.y || ii >= ingame->map_size.x)
	  continue ;	
	bool att = BITGET(ingame->attack_map, ii, jj, ingame->map_size.x);
	bool bld = BITGET(ingame->build_map, ii, jj, ingame->map_size.x);

	((unsigned int*)ingame->action_screen->pixels)[i + j * ingame->action_screen->clipable.buffer.width] = 0;
	if (att)
	  ((unsigned int*)ingame->action_screen->pixels)[i + j * ingame->action_screen->clipable.buffer.width] |= TO_RED(128) | TO_ALPHA(128);
	if (bld)
	  ((unsigned int*)ingame->action_screen->pixels)[i + j * ingame->action_screen->clipable.buffer.width] |= TO_BLUE(128) | TO_ALPHA(128);
      }
  bunny_blit(&ingame->program->screen->buffer, &ingame->action_screen->clipable, NULL);

  t_bunny_size bsiz = {ingame->brush_size, ingame->brush_size};
  t_bunny_size lbsiz = {ingame->brush_size - 3, ingame->brush_size - 3};
  unsigned int bcol = ALPHA(64, WHITE);
  unsigned int ocol = ALPHA(128, WHITE);
  t_bunny_position bpos = {
    ingame->program->screen->buffer.width - 20,
    ingame->program->screen->buffer.height - 20
  };

  bunny_set_disk(&ingame->program->screen->buffer, bpos, bsiz, bcol, 0, 3);
  bunny_set_disk(&ingame->program->screen->buffer, bpos, lbsiz, 0, ocol, 3);

}
