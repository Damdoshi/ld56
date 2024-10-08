
#include	<stdarg.h>
#include	"program.h"

static void	remove_event(t_ingame		*ing,
			     size_t		evt)
{
  memcpy(&ing->event_list[evt],
	 &ing->event_list[ing->event_len - 1],
	 sizeof(ing->event_list[evt])
	 );
  ing->event_len -= 1;
}

int		ingame_event(t_ingame		*ing)
{
  size_t	i;
  
  for (i = 0; i < NBRCELL(ing->event_list) && i < ing->event_len;)
    if (ing->event_list[i].event_date <= ing->frame_counter)
      {
	if (ing->event_list[i].type == KILL_PIXEL)
	  ingame_pixel_delete(ing, ing->event_list[i].pos, 1);
	if (ing->event_list[i].type == RETRY)
	  {
	    remove_event(ing, i);
	    return (SWITCH_CONTEXT);
	  }
	if (ing->event_list[i].type == GAME_OVER)
	  {
	    remove_event(ing, i);
	    ing->program->context = CREDIT;
	    return (SWITCH_CONTEXT);
	  }
	remove_event(ing, i);
      }
    else
      ++i;
  return (GO_ON);
}


