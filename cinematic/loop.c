// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"cinematic.h"

t_bunny_response	cinematic_loop(t_cinematic		*cinematic)
{
  double		now = bunny_get_current_time();
  t_bunny_response	ret;

  ret = bunny_cinematic(cinematic->cinematic, BCE_NO_EVENT, now - cinematic->last_action);
  cinematic->last_action = now;
  if (ret == EXIT_ON_SUCCESS)
    {
      cinematic->program->context = cinematic->following_context;
      return (SWITCH_CONTEXT);
    }
  return (GO_ON);
}

