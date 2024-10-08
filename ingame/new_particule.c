#include		"program.h"

void			new_particule(t_ingame				*ing,
				      double				death_time,
				      t_bunny_position			pos,
				      t_bunny_accurate_position		spos,
				      uint32_t				color,
				      t_particule_action		action)
{
  t_particule		*particule = &ing->particules;
  
  if (particule->nb_particule >= MAX_PARTICULE)
    return ;
  particule->color[particule->nb_particule] = color;
  particule->death_time[particule->nb_particule] = death_time;
  particule->pos[particule->nb_particule].x = pos.x;
  particule->pos[particule->nb_particule].y = pos.y;
  particule->spos[particule->nb_particule].x = spos.x;
  particule->spos[particule->nb_particule].y = spos.y;
  particule->action[particule->nb_particule] = action;
  particule->nb_particule ++;
  return ;
}
