
#include		"program.h"

const char		*gl_files[LAST_UNIT_TYPE] = {
  "./res/ingame/gfx/hero.dab",
  "./res/ingame/gfx/wallspider.dab",
  "./res/ingame/gfx/eatspider.dab",
  "./res/ingame/gfx/lightspider.dab",
  "./res/ingame/gfx/badspider.dab"
};

t_unit_action		gl_action[LAST_UNIT_TYPE] = {
  ingame_player_action,
  ingame_spider_action,
  ingame_spider_action,
  ingame_spider_action,
  ingame_spider_action,
};

int			ingame_new_unit(t_ingame	*ing,
					t_unit_type	type,
					t_bunny_position pos)
{
  t_bunny_configuration	*cnf;

  assert(ing->last_unit < NBRCELL(ing->units));
  t_unit		*unit = &ing->units[ing->last_unit++];

  ingame_load_sprite(ing, gl_files[type], &unit->sprite);
  assert((cnf = bunny_open_configuration(gl_files[type], NULL)));

  if (!bunny_configuration_getf(cnf, &unit->area.w, "ColWidth"))
    unit->area.w = unit->sprite->clipable.clip_width;
  if (!bunny_configuration_getf(cnf, &unit->area.h, "ColHeight"))
    unit->area.h = unit->sprite->clipable.clip_height;

  unit->area.x = pos.x;
  unit->area.y = pos.y;

  if (!bunny_configuration_getf(cnf, &unit->speed.x, "SpeedX"))
    unit->speed.x = 2;
  if (!bunny_configuration_getf(cnf, &unit->speed.y, "SpeedY"))
    unit->speed.y = -3.7;

  unit->target.x = unit->area.x;
  unit->target.y = unit->area.y;
  unit->target_action = SELECTION; // "Ne fait rien"
  unit->action = gl_action[type];

  bunny_delete_configuration(cnf);
  return (ing->last_unit - 1);
}
