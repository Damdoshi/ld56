#include		"load_file.h"

t_map			*load_map(t_bunny_pixelarray		*_map)
{
  t_element		*map_elem;
  t_map			*map_property;
  t_bunny_pixelarray	*map = _map;
  int64_t		largeur = map->clipable.buffer.width;
  int64_t		hauteur = map->clipable.buffer.height;
  int64_t		size = largeur * hauteur;
  t_bunny_color		color_pix;

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
  for (int64_t i = 0; i < size; i ++)
    {
      color_pix.full = ((uint32_t*)(map->pixels))[i];
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
    }
  return (map_property);
}
