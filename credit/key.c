// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"credit.h"

t_bunny_response		credit_key(t_bunny_event_state	state,
					    t_bunny_keysym	sym,
					    t_credit		*credit)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE || sym == BKS_RETURN || sym == BKS_SPACE)
    {
      credit->program->context = MAIN_MENU;
      return (SWITCH_CONTEXT);
    }
  return (GO_ON);
}
