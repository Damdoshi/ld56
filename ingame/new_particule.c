#include		"program.h"

void			new_particule(t_particule			*particule,
				      double				death_time,
				      t_bunny_accurate_position		pos,
				      t_bunny_accurate_position		spos,
				      uint32_t				color)
{
  if (particule->nb_particule >= MAX_PARTICULE)
    return ;
  particule->color[particule->nb_particule] = color;
  particule->death_time[particule->nb_particule] = death_time;
  particule->pos[particule->nb_particule].x = pos.x;
  particule->pos[particule->nb_particule].y = pos.y;
  particule->spos[particule->nb_particule].x = spos.x;
  particule->spos[particule->nb_particule].y = spos.y;
  particule->nb_particule ++;
  return ;
}
