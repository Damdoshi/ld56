
#include		"program.h"

bool			ingame_progress_health(t_ingame		*ing)
{
  if (fabs(ing->health_target - ing->health) < 0.01)
    return (ing->health > 0);

  if (ing->health_target > ing->health)
    if ((ing->health += 0.01) > ing->health_target)
      ing->health = ing->health_target;

  if (ing->health_target < ing->health)
    if ((ing->health -= 0.01) < ing->health_target)
      ing->health = ing->health_target;

  if (ing->health <= 0)
    return (false);
  return (true);
}
