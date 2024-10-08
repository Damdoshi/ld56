#include		"program.h"

void			check_particule(t_ingame		*ingame)
{
  t_particule		*particule = &ingame->particules;
  double		time = bunny_get_current_time();

  for (int32_t i = 0; i < particule->nb_particule; i ++)
    {
      if (particule->death_time[i] < time)
	{
	  delete_particule(particule, i);
	  i --;
	}
      else if (particule->action[i](ingame, particule, i) == true)
	{
	  delete_particule(particule, i);
	  i --;
	}
    }
}
