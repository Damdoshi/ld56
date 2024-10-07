
#include		"program.h"

bool			ingame_progress_health(t_ingame		*ing)
{
  if (fabs(ing->health - ing->player->health) < 0.01)
    return (ing->health > 0);

  if (ing->health > ing->player->health)
    if ((ing->health += 0.01) > ing->player->health)
      ing->health = ing->player->health;

  if (ing->health < ing->player->health)
    if ((ing->health -= 0.01) < ing->player->health)
      ing->health = ing->player->health;

  if (ing->health <= 0)
    return (false);
  return (true);
}
