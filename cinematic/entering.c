// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"cinematic.h"

t_bunny_response	cinematic_entering(t_cinematic		*cinematic)
{
  const char		*lng = "EN";

  bunny_configuration_getf(cinematic->program->configuration, &lng, "Language");
  assert((cinematic->cinematic = bunny_load_cinematic(cinematic->configuration, lng)));
  cinematic->last_action = bunny_get_current_time();
  return (GO_ON);
}

