// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game


#ifndef				__credit_H__
# define			__credit_H__

struct				s_program;
typedef struct			s_credit
{
  struct s_program		*program;
  t_bunny_pixelarray		*screen;
  t_bunny_font			*font;
  t_bunny_pixelarray		*fire;
  t_bunny_picture		*back;
}				t_credit;

#endif	/*			__credit_H__		*/
