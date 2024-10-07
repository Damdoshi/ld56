#include		"program.h"

void			check_particule(t_ingame		*ingame)
{
  t_particule		*particule = &ingame->particules;
  double		time = bunny_get_current_time();
  t_bunny_position	pos;

  for (int32_t i = 0; i < particule->nb_particule; i ++)
    {
      if (particule->death_time[i] < time && 0)
	{
	  delete_particule(particule, i);
	  i --;
	}
      else
	{
	  pos.x = particule->pos[i].x - ingame->camera.x;
	  pos.y = particule->pos[i].y - ingame->camera.y;


	  for (size_t j = 0; j < 3; ++j)
	    {
	      bunny_set_pixel(&ingame->program->screen->buffer, pos, particule->color[i]);
	      pos.x += rand() % 3 - 1;
	      pos.y += rand() % 3 - 1;
	    }
	  
	  
	  ingame->aura->clipable.color_mask.full = particule->color[i] | BLACK;
	  // bunny_blit(&ingame->program->screen->buffer, &ingame->aura->clipable, &pos);
	  particule->pos[i].x += particule->spos[i].x;
	  particule->pos[i].y += particule->spos[i].y;
	  particule->spos[i].y += 0.03;
	}
    }
}
