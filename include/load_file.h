#ifndef			__LOAD_FILE_H__
#define			__LOAD_FILE_H__

#include		<lapin.h>

typedef enum		e_element
  {
    AIR,		//transparent
    TERRE,		//GREEN
    ROCHE,		//BLACK
    EAU,		//BLUE
    EXPLOSIF		//RED
  }			t_element;

typedef struct		s_map
{
  t_bunny_pixelarray	*map;
  t_element		*map_composant;
  int64_t		size;
}			t_map;

t_map			*load_map(t_bunny_pixelarray	*map)

#endif//		__LOAD_FILE_H__
