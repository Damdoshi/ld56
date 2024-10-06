#include		"program.h"

void			check_particule(t_ingame		*ingame)
{
  t_particule		*particule = &ingame->particules;
  double		time = bunny_get_current_time();
  t_bunny_position	pos;

  for (int32_t i = 0; i < particule->nb_particule; i ++)
    {
      if (particule->death_time[i] >= time)
	{
	  delete_particule(particule, i);
	  i --;
	}
      else
	{
	  pos.x = particule->pos[i].x;
	  pos.y = particule->pos[i].y;
	  bunny_set_pixel(&ingame->program->screen->buffer, pos, particule->color[i]);
	  particule->pos[i].x += particule->spos[i].x;
	  particule->pos[i].y += particule->spos[i].y;
	}
    }
}
