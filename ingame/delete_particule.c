#include		"program.h"

void			delete_particule(t_particule			*particule,
					 int32_t			index)
{
  particule->nb_particule --;
  particule->color[index] = particule->color[particule->nb_particule];
  particule->death_time[index] = particule->death_time[particule->nb_particule];
  particule->pos[index].x = particule->pos[particule->nb_particule].x;
  particule->pos[index].y = particule->pos[particule->nb_particule].y;
  particule->spos[index].x = particule->spos[particule->nb_particule].x;
  particule->spos[index].y = particule->spos[particule->nb_particule].y;
  particule->action[index] = particule->action[particule->nb_particule];
}
