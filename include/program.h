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
# include			"context_headers.template"

typedef enum			e_context
  {
    FIRST_CONTEXT,
    BUNNY_SPLASH		= FIRST_CONTEXT,
    MENU_GAME,
    GAME,
# include			"context_enumeration.template"
    LAST_CONTEXT
  }				t_context;

extern t_bunny_context		gl_context[LAST_CONTEXT];

typedef struct			s_program
{
  t_bunny_window		*window;
  t_bunny_configuration		*configuration;
  int				scale_mode;
  bool				keep_pixel_ratio;
  t_bunny_picture		*hdscreen;
  t_bunny_picture		*screen;
  // Le contexte actuel ou celui qui va immédiatement suivre
  t_context			context;
  // Pour les contextes a sortie multiple... ou aller après?
  t_context			next_context;
  
  t_bunny_splash_screen		bunny_splash;
# include			"context_attribute.template"
}				t_program;

t_bunny_position		get_real_mouse_position(t_bunny_picture         *screen);

#endif	//			__PROGRAM_H__

