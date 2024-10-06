
#include		"program.h"

const char		*gl_files[LAST_UNIT_TYPE] = {
  "", // mettre le joueur ici
  "./res/ingame/gfx/wallspider.dab",
  "./res/ingame/gfx/eatspider.dab",
  "./res/ingame/gfx/lightspider.dab",
  "./res/ingame/gfx/badspider.dab"
};

bool			ingame_new_unit(t_ingame	*ing,
					t_unit_type	type,
					t_bunny_position pos)
{
  t_bunny_configuration	*cnf;

  if (ing->last_unit >= NBRCELL(ing->units))
    return (false);
  t_unit		*unit = &ing->units[ing->last_unit++];

  assert((unit->sprite = bunny_load_sprite("")));
  assert((cnf = bunny_open_configuration("", NULL)));

  if (!bunny_configuration_getf(cnf, &unit->area.w, "ColWidth"))
    unit->area.w = unit->sprite->clipable.clip_width;
  if (!bunny_configuration_getf(cnf, &unit->area.h, "ColHeight"))
    unit->area.h = unit->sprite->clipable.clip_height;

  unit->area.x = pos.x;
  unit->area.y = pos.y;

  if (!bunny_configuration_getf(cnf, &unit->speed.x, "SpeedX"))
    unit->speed.x = 2;
  if (!bunny_configuration_getf(cnf, &unit->speed.x, "SpeedY"))
    unit->speed.y = -3.7;

  return (true);
}
