#include		"load_file.h"

t_map			*load_map(t_bunny_pixelarray		*map)
{
  t_element		*map_elem;
  t_map			*map_property;
  int			size;
  t_bunny_color		color_pix;
  int			i;

  if (!map)
    return(NULL);
  size = map->clipable.buffer.width * map->clipable.buffer.height;
  if ((map_property = malloc(sizeof(t_map))) == NULL)
    {
      puts("echec de malloc : load_file.c");
      return (NULL);
    }
  if ((map_elem = malloc(sizeof(t_element) * size)) == NULL)
    {
      puts("echec de malloc : load_file.c");
      return (NULL);
    }
  map_property->map = map;
  map_property->map_composant = map_elem;
  map_property->size = size;
  for (i = 0; i < size; i ++)
    {
      color_pix.full = ((unsigned int*)(map->pixels))[i];
      if (color_pix.argb[3] == 0)
	map_elem[i] = AIR;
      else if (color_pix.full == GREEN)
	map_elem[i] = TERRE;
      else if (color_pix.full == BLACK)
	map_elem[i] = ROCHE;
      else if (color_pix.full == BLUE)
	map_elem[i] = EAU;
      else if (color_pix.full == RED)
	map_elem[i] = EXPLOSIF;
      else if (color_pix.full == YELLOW)
	map_elem[i] = SAND;
      else if (color_pix.full == PINK2)
	map_elem[i] = FIRE;
    }
  return (map_property);
}
