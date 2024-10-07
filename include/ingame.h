// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#ifndef				__ingame_H__
# define			__ingame_H__

#include			<lapin.h>

# define			MIN_PIXEL_TO_HOLD			1
# define			COEF_CLIMBING_HEIGHT			5

# define			HERO_MAX_SPEED				2
# define			MAX_PARTICULE				10240

# define			BITGET(bf, x, y, w)			\
  bunny_bitfield_get((bf), (x) + (y) * (w))
# define			BITSET(bf, x, y, w)			\
  bunny_bitfield_set((bf), (x) + (y) * (w))
# define			BITCLR(bf, x, y, w)			\
  bunny_bitfield_clr((bf), (x) + (y) * (w))

typedef enum			e_unit_status
  {
    IDLE,
    WALKING,
    FALLING,
    JUMPING,
    ATTACKING,
    CRAWLING
  }				t_unit_status;

typedef enum			e_event_type
  {
    KILL_PIXEL
  }				t_event_type;

typedef struct			s_game_event
{
  t_event_type			type;
  int				event_date;
  t_bunny_position		pos;
}				t_game_event;

typedef enum			e_action
  {
    SELECTION,
    ATTACK,
    CONSTRUCTION
  }				t_action;

typedef enum			e_unit_type
  {
    HERO,
    WALLSPIDER,
    EATSPIDER,
    LIGHTSPIDER,
    BADSPIDER,
    LAST_UNIT_TYPE
  }				t_unit_type;

typedef enum			e_element
  {
    AIR,			//transparent
    ROCK,			//BLACK
    WATER,			//BLUE
    EARTH,			//GREEN
    EXPLODE,			//RED
    SAND,			//YELLOW
    FIRE			//PINK2
  }				t_element;

struct				s_ingame;
struct				s_unit;
typedef void			(*t_unit_action)(struct s_ingame	*ing,
						 struct s_unit		*unit);

typedef struct			s_unit
{
  t_unit_type			type;
  t_unit_status			status;
  t_bunny_accurate_area		area;
  t_bunny_accurate_position	inertia;
  t_bunny_sprite		*sprite;
  bool				selected;
  t_bunny_accurate_position	speed; // Vitesse horizontale et force du saut
  t_unit_action			action;
  t_bunny_position		target;	// Ou dois je aller?
  t_action			target_action; // pour faire quoi?
  unsigned int			light_color;
  double			light_radius;
  double			health;
  t_bunny_effect		*hurt[16];
}				t_unit;

typedef enum			s_sfx
{
  MENU = 0,
  PLAYER,
  NPC,
  ENEMY_NPC,
  AMBIENT,
  LAST_SFX_CATEGORY
}				t_sfx;

typedef struct			s_particule
{
  double			death_time[MAX_PARTICULE];
  uint32_t			color[MAX_PARTICULE];
  t_bunny_accurate_position	pos[MAX_PARTICULE];
  t_bunny_accurate_position	spos[MAX_PARTICULE];
  int32_t			nb_particule;
}				t_particule;

struct				s_program;
typedef struct			s_ingame
{
  struct s_program		*program;
  t_bunny_sprite		*sprites[4096];
  size_t			last_sprite;
  int				frame_counter;
  t_particule			particules;
  t_bunny_music			*music;

  ///// VIE
  t_unit			*player;
  int				life;
  t_bunny_sprite		*skull;
  double			health;
  t_bunny_sprite		*health_track;
  t_bunny_sprite		*health_bar;
  t_bunny_sprite		*health_renderer;

  //
  t_bunny_sprite		*cursor;
  size_t			cursor_type;
  //
  t_unit			units[4096];
  size_t			last_unit;
  //
  t_unit			*selection[4096];
  size_t			last_selection;

  //// SON
  t_bunny_effect		*sfx[LAST_SFX_CATEGORY][128];
  int				step_frame;

  //// NIVEAU
  t_bunny_picture		*background;
  t_bunny_picture		*remain_map;
  t_bunny_pixelarray		*color_map;
  t_element			*physic_map;
  t_bunny_picture		*foreground;
  t_bunny_picture		*whitescreen;
  t_bunny_pixelarray		*fire;
  t_bunny_position		map_size;

  t_bunny_bitfield		*attack_map;
  t_bunny_bitfield		*build_map;
  
  t_game_event			event_list[4096];
  size_t			event_len;

  t_bunny_accurate_area		camera;
  t_bunny_accurate_area		select;
  bool				select_on;
}				t_ingame;

void				ingame_get_hurt(t_ingame		*ing,
						t_unit			*unit,
						double			damage);
bool				ingame_progress_health(t_ingame		*ing);

void				ingame_end_select(t_ingame		*ing);
void				ingame_start_select(t_ingame		*ing);
void				ingame_move_select(t_ingame		*ing);
void				ingame_load_sprite(t_ingame		*ingame,
						   const char		*file,
						   t_bunny_sprite	**sprite);
void				ingame_free_sprite(t_ingame		*ingame,
						   t_bunny_sprite	**sprite);
void				ingame_display_health_bar(t_ingame	*ingame);
void				ingame_display_life(t_ingame		*ingame);
void				ingame_display_mouse(t_ingame		*ingame);
void				ingame_display_selection(t_ingame	*ing);

void				ingame_event(t_ingame			*game);
void				ingame_add_event(t_ingame		*game,
						 int			date,
						 t_event_type		evt,
						 ...);

bool				ingame_is_orphan(t_ingame		*ing,
						 int			x,
						 int			y);

bool				ingame_load_map(t_ingame		*ing,
						const char		*file);

int				ingame_get_pixel(t_ingame		*ing,
						 int			x,
						 int			y);
void				ingame_pixel_delete(t_ingame		*ing,
						    t_bunny_position	pos);
void				ingame_pixel_explosif(t_ingame		*ing,
						      t_bunny_position	pos,
						      double		r);
void				pixel_move(t_ingame			*ing,
					   t_unit			*unit,
					   t_bunny_accurate_position	target_pos);

void				sfx_loader(t_ingame			*ing);

void				manage_inertia(t_ingame			*ing,
					       t_unit			*unit);
bool				ingame_bottom_collision(t_ingame	*ing,
							t_unit		*unit);
bool				ingame_top_collision(t_ingame		*ing,
						     t_unit		*unit);

void				ingame_go(t_ingame			*ing,
					  t_unit			*unit,
					  int				x);
void				ingame_jump(t_ingame			*ing,
					    t_unit			*unit);

int 				ingame_new_unit(t_ingame		*ing,
						t_unit_type		type,
						t_bunny_position	pos);
void				new_particule(t_particule		*particule,
					      double			death_time,
					      t_bunny_accurate_position	pos,
					      t_bunny_accurate_position	spos,
					      uint32_t			color);
void				delete_particule(t_particule		*particule,
						 int32_t		index);
void				check_particule(t_ingame		*ingame);

void				ingame_player_action(t_ingame		*ing,
						     t_unit		*unit);
void				ingame_spider_action(t_ingame		*ing,
						     t_unit		*unit);

#endif	/*			__ingame_H__				*/

