
#include		"program.h"

bool			ingame_load_map(t_ingame		*ing,
					const char		*file)
{
  t_bunny_pixelarray	*physic_map;
  const char		*str;
  t_bunny_configuration	*cnf;
  bool			tmp;

  assert((cnf = bunny_open_configuration(file, NULL)));

  assert((bunny_configuration_getf(cnf, &str, "Eatable")));
  assert((ing->color_map = bunny_load_pixelarray(str)));
  assert((bunny_configuration_getf(cnf, &str, "Physic")));
  assert((physic_map = bunny_load_pixelarray(str)));
  
  assert((ing->color_map->clipable.buffer.width == physic_map->clipable.buffer.width));
  assert((ing->color_map->clipable.buffer.height == physic_map->clipable.buffer.height));

  if ((bunny_configuration_getf(cnf, &str, "Remain")))
    {
      assert((ing->remain_map = bunny_load_picture(str)));
      assert((ing->color_map->clipable.buffer.width == ing->remain_map->buffer.width));
      assert((ing->color_map->clipable.buffer.height == ing->remain_map->buffer.height));
    }
  else
    ing->remain_map = NULL;

  ing->map_size.x = ing->color_map->clipable.buffer.width;
  ing->map_size.y = ing->color_map->clipable.buffer.height;

  if (bunny_configuration_getf(cnf, &tmp, "Fire") && tmp)
    assert((ing->fire = bunny_new_pixelarray(ing->map_size.x, ing->map_size.y)));
  else
    ing->fire = NULL;
  
  if ((bunny_configuration_getf(cnf, &str, "Background")))
    assert((ing->background = bunny_load_picture(str)));
  else
    ing->background = NULL;
    
  if ((bunny_configuration_getf(cnf, &str, "Foreground")))
    assert((ing->foreground = bunny_load_picture(str)));
  else
    ing->foreground = NULL;

  size_t		size = ing->map_size.x * ing->map_size.y;

  ing->attack_map = bunny_new_bitfield(size);
  ing->build_map = bunny_new_bitfield(size);

  for (size_t i ; i < size; i++)
    {

    }

  assert((ing->physic_map = malloc(sizeof(t_element) * size)));
  t_bunny_color		color;
  size_t		i;
  t_bunny_position	pos;

  ing->player = NULL;
  for (i = 0; i < size; i++)
    {
      color.full = ((unsigned int*)(physic_map->pixels))[i];
      bunny_bitfield_set(ing->attack_map, i);
      bunny_bitfield_set(ing->build_map, i);
      if (color.argb[3] == 0)
	{
	  ing->physic_map[i] = AIR;
	  bunny_bitfield_clr(ing->attack_map, i);
	  bunny_bitfield_clr(ing->build_map, i);
	}
      else if (color.full == GREEN)
	ing->physic_map[i] = EARTH;
      else if (color.full == BLACK)
	ing->physic_map[i] = ROCK;
      else if (color.full == BLUE)
	ing->physic_map[i] = WATER;
      else if (color.full == RED)
	ing->physic_map[i] = EXPLODE;
      else if (color.full == YELLOW)
	ing->physic_map[i] = SAND;
      else if (color.full == PINK2)
	ing->physic_map[i] = FIRE;
      else if (color.full == TEAL && ing->player == NULL)
	{
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ing->player = &ing->units[ingame_new_unit(ing, HERO, pos)];
	}
      else if (color.full == WHITE)
	{
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ingame_new_unit(ing, LIGHTSPIDER, pos);
	}
      else if (color.full == PURPLE)
	{
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ingame_new_unit(ing, EATSPIDER, pos);
	}
      // else { faire les autres monstres }
    }
  assert((ing->player != NULL));
  bunny_delete_clipable(&physic_map->clipable);
  bunny_delete_configuration(cnf);
  return (true);
}

