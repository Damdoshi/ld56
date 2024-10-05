
#include	<stdarg.h>
#include	"program.h"

void		ingame_add_event(t_ingame	       *ing,
				 int			date,
				 t_event_type		evt,
				 ...)
{
  t_game_event	*gev = &ing->event_list[ing->event_len];
  va_list	lst;
  
  va_start(lst, evt);
  gev->type = evt;
  gev->event_date = date;
  if (evt == KILL_PIXEL)
    gev->pos = va_arg(lst, t_bunny_position);
}

