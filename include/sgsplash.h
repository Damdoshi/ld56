// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game


#ifndef				__sgsplash_H__
# define			__sgsplash_H__

#include			<lapin.h>

double				efclamp(double				v,
					double				min,
					double				max);

typedef struct			s_zposition
{
  double			x;
  double			y;
  double			z;
}				t_zposition;

struct				s_program;
enum				e_context;
typedef struct			s_sgsplash
{
  struct s_program		*program;
  uint32_t			nb_pts;
  enum e_context		*current_context;
  uint32_t			*col;
  t_zposition			*pts;
  t_bunny_window		*win;
  t_bunny_pixelarray		*pix;
  t_bunny_pixelarray		*pause;
  t_bunny_picture   		*pic;
  t_bunny_font			*font;
  t_bunny_position		pos;
  t_zposition			rot;
  double			start_time;
  double			now_time;
  double			duration;
  t_bunny_color			color;
}				t_sgsplash;

unsigned int			get_pixel(const t_bunny_pixelarray	*px,
					  t_bunny_position		pos);

double				efget_ratio(double			value,
					    double			min,
					    double			max);

double				efget_value(double			ratio,
					    double			min,
					    double			max);


void				efclear_pixelarray(t_bunny_pixelarray   *picture,
						   uint32_t             color);

unsigned int			get_pixel(const t_bunny_pixelarray	*px,
					  t_bunny_position		pos);

void				efset_pixel(t_bunny_pixelarray		*px,
					    t_bunny_position		pos,
					    uint32_t			color);

void				tset_pixel(const t_bunny_pixelarray	*picture,
					   t_bunny_position		pos,
					   t_bunny_color		color);

int32_t				convert_integer(int32_t			nbr,
						char			*decimal);

void				boom_galax(t_sgsplash			*spa);

void				app_nom(t_sgsplash			*spa,
					double				ratio);

#endif	/*			__sgsplash_H__		*/
