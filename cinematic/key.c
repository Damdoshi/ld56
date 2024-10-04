// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"cinematic.h"

t_bunny_response		cinematic_key(t_bunny_event_state	state,
					      t_bunny_keysym		sym,
					      t_cinematic		*cinematic)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    goto StopAndLeave;
  t_bunny_cinematic_event	evt = BCE_NO_EVENT;
  double			now = bunny_get_current_time();
  t_bunny_response		ret;

  if (sym == BKS_SPACE || sym == BKS_RETURN)
    evt = BCE_TERMINATE_EVENT;
  ret = bunny_cinematic(cinematic->cinematic, evt, now - cinematic->last_action);
  cinematic->last_action = now;
  if (ret != EXIT_ON_SUCCESS)
    return (GO_ON);

 StopAndLeave:
  bunny_cinematic_stop(cinematic->cinematic);
  cinematic->program->context = cinematic->following_context;
  return (SWITCH_CONTEXT);  
}
