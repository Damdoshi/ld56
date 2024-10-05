
#include		"program.h"

bool			ingame_load_map(t_ingame		*ing,
					const char		*file)
{
  t_bunny_pixelarray	*color_map;

  if (!(color_map = bunny_load_pixelarray(file)))
    return (false);
  ing->map_size.x = color_map->clipable.buffer.width;
  ing->map_size.y = color_map->clipable.buffer.height;
  size_t		size = ing->map_size.x * ing->map_size.y;

  if ((ing->physic_map = malloc(sizeof(t_element) * size)) == NULL)
    {
      puts("echec de malloc : " __FILE__);
      return (false);
    }
  t_bunny_color		color_pix;
  size_t		i;

  ing->player = NULL;
  for (i = 0; i < size; i++)
    {
      color_pix.full = ((unsigned int*)(color_map->pixels))[i];
      if (color_pix.argb[3] == 0)
	ing->physic_map[i] = AIR;
      else if (color_pix.full == GREEN)
	ing->physic_map[i] = EARTH;
      else if (color_pix.full == BLACK)
	ing->physic_map[i] = ROCK;
      else if (color_pix.full == BLUE)
	ing->physic_map[i] = WATER;
      else if (color_pix.full == RED)
	ing->physic_map[i] = EXPLODE;
      else if (color_pix.full == YELLOW)
	ing->physic_map[i] = SAND;
      else if (color_pix.full == PINK2)
	ing->physic_map[i] = FIRE;
      else if (color_pix.full == TEAL && ing->player == NULL)
	{
	  if (ing->last_unit >= NBRCELL(ing->units))
	    return (false);
	  ing->player = &ing->units[ing->last_unit++];
	  ing->player->type = HERO;
	  ing->player->area.w = 50;
	  ing->player->area.h = 50;
	  ing->player->area.x = i % ing->map_size.x;
	  ing->player->area.y = i / ing->map_size.x;
	  printf("Position %f %f\n", ing->player->area.x, ing->player->area.y);
	}
    }
  if (ing->player == NULL)
    return (false);
  
  bunny_delete_clipable(&color_map->clipable);
  return (true);
}

