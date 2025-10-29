// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#ifndef				__PROGRAM_H__
# define			__PROGRAM_H__
# include			<lapin.h>
# include			<assert.h>
# include			"tekfunction.h"
# include			"context_headers.template"

typedef enum			e_context
  {
    FIRST_CONTEXT,
    BUNNY_SPLASH		= FIRST_CONTEXT,
# include			"context_enumeration.template"
    LAST_CONTEXT
  }				t_context;

extern t_bunny_context		gl_context[LAST_CONTEXT];

typedef struct			s_program
{
  t_bunny_window		**window;
  int				nbr_window;
  t_bunny_configuration		*configuration;
  int				scale_mode;
  bool				keep_pixel_ratio;
  t_bunny_picture		*hdscreen;
  t_bunny_picture		*screen;
  // Le contexte actuel ou celui qui va immédiatement suivre
  t_context			context;
  // Pour les contextes a sortie multiple... ou aller après?
  t_context			next_context;

  bool				no_music;
  bool				no_light;
  t_bunny_splash_screen		bunny_splash;
# include			"context_attribute.template"
}				t_program;

int				fire(t_bunny_pixelarray		*px,
				     bool			underfire,
				     t_bunny_area		*camera);
void				set_fire_pixel(int		x,
					       int		y);

t_bunny_position		get_real_mouse_position(t_bunny_picture *screen);

double				afabs(double			x);

void				draw_rect(t_ingame		*ing,
					  t_bunny_accurate_area	*area);

double				distance(double			x1,
					 double			y1,
					 double			x2,
					 double			y2);


double				fcos(double			v);
double				fsin(double			v);

void				sound_play(t_bunny_effect	*eff);

#endif	//			__PROGRAM_H__

