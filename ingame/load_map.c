#include		"program.h"

bool			load_map(t_ingame			*ing,
				 const char			*file)
{
  t_bunny_pixelarray	*color_map;

  if (!(color_map = bunny_load_pixelarray(file)))
    return (false);
  size_t		size = ing->map_size.x * ing->map_size.y;

  ing->map_size.x = color_map->clipable.buffer.width;
  ing->map_size.y = color_map->clipable.buffer.height;
  if ((ing->map = malloc(sizeof(t_element) * size)) == NULL)
    {
      puts("echec de malloc : " __FILE__);
      return (false);
    }  
  t_bunny_color		color_pix;
  size_t		i;

  for (i = 0; i < size; i++)
    {
      color_pix.full = ((unsigned int*)(color_map->pixels))[i];
      if (color_pix.argb[3] == 0)
	ing->map[i] = AIR;
      else if (color_pix.full == GREEN)
	ing->map[i] = EARTH;
      else if (color_pix.full == BLACK)
	ing->map[i] = ROCK;
      else if (color_pix.full == BLUE)
	ing->map[i] = WATER;
      else if (color_pix.full == RED)
	ing->map[i] = EXPLODE;
      else if (color_pix.full == YELLOW)
	ing->map[i] = SAND;
      else if (color_pix.full == PINK2)
	ing->map[i] = FIRE;
    }
  return (true);
}
