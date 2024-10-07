
#include		"program.h"

bool			ingame_progress_health(t_ingame		*ing)
{
  if (ing->health == 0)
    return (true);

  if (ing->health < ing->player->health)
    if ((ing->health += 0.01) > ing->player->health)
      ing->health = ing->player->health;

  if (ing->health > ing->player->health)
    if ((ing->health -= 0.01) < ing->player->health)
      ing->health = ing->player->health;
  
  // Detection de l'evenement de mort
  if (ing->health <= 0)
    {
      ing->health = 0;
      return (false);
    }
  return (true);
}
