
#include		"program.h"

bool			ingame_load_map(t_ingame		*ing,
					const char		*file)
{
  t_bunny_pixelarray	*color_map;

  if (!(color_map = bunny_load_pixelarray(file)))
    {
       puts("echec de load_pixelarray : " __FILE__);
      return (false);
    }
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
  t_bunny_position	pos;

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
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ingame_new_unit(ingame, HERO, pos);
	}
      else if (color_pix.full == LIGHTSPIDER_SPAWN)
	{
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ingame_new_unit(ingame, LIGHTSPIDER, pos);
	}
      else if (color_pix.full == EATSPIDER_SPAWN)
	{
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ingame_new_unit(ingame, EATSPIDER, pos);
	}
      // else { faire les autres monstres }
    }
  if (ing->player == NULL)
    {
      puts("pas de joueur sur la carte : " __FILE__);
      return (false);
    }
  bunny_delete_clipable(&color_map->clipable);
  return (true);
}

