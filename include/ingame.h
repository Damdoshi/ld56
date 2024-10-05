// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game


#ifndef				__ingame_H__
# define			__ingame_H__

typedef enum			e_unit_type
  {
    HERO,
    WALLSPIDER,
    EATSPIDER
  }				t_unit_type;

typedef struct			s_unit
{
  t_unit_type			type;
  t_bunny_accurate_area		area;
  bool				selected;
}				t_unit;

struct				s_program;
typedef struct			s_ingame
{
  struct s_program		*program;
  t_bunny_sprite		*sprites[4096];
  size_t			last_sprite;

  t_bunny_sprite		*mmx;
  t_bunny_sprite		*cursor;

  t_unit			units[4096];
  size_t			last_unit;

  t_unit			*selection[4096];
  size_t			last_selection;
  
  t_bunny_accurate_area		camera;
  t_bunny_accurate_area		select;
  bool				select_on;
}				t_ingame;

void				ingame_display_selection(t_ingame	*ing);
void				ingame_end_select(t_ingame		*ing);
void				ingame_start_select(t_ingame		*ing);
void				ingame_move_select(t_ingame		*ing);
t_bunny_position		ingame_get_real_mouse_position(t_ingame *ing);
void				ingame_load_sprite(t_ingame		*ingame,
						   const char		*file,
						   t_bunny_sprite	**sprite);
void				ingame_free_sprite(t_ingame		*ingame,
						   t_bunny_sprite	**sprite);

#endif	/*			__ingame_H__			*/
