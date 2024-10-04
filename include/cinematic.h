// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game


#ifndef				__cinematic_H__
# define			__cinematic_H__

struct				s_program;
typedef struct			s_cinematic
{
  struct s_program		*program;
  const char			*configuration;
  int				following_context;
  t_bunny_cinematic		*cinematic;
  double			last_action;
}				t_cinematic;

#endif	/*			__cinematic_H__		*/
