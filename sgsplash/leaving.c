// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"sgsplash.h"

void			sgsplash_leaving(t_bunny_response	response,
					t_sgsplash		*spa)
{
  (void)response;
  bunny_delete_clipable(&spa->pix->clipable);
  spa->start_time = spa->now_time = 0;
  spa->duration = 0;
  *spa->current_context = MAIN_MENU;
  bunny_delete_clipable(spa->pic);
  free(spa->col);
  free(spa->pts);
}
