// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game


#ifndef				__main_menu_H__
# define			__main_menu_H__

struct				s_program;
typedef struct			s_main_menu
{
  struct s_program		*program;
  t_bunny_picture		*menu;
  t_bunny_font			*text_menu[2];
  t_bunny_area			pos_txt[2];
  t_bunny_sprite		*cursor;
  //
}				t_main_menu;

#endif	/*			__main_menu_H__		*/
