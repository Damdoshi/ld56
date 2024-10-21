
#include		"program.h"

bool			ingame_load_map(t_ingame		*ing,
					const char		*file)
{
  t_bunny_pixelarray	*physic_map;
  const char		*str;
  t_bunny_configuration	*cnf;
  bool			tmp;

  if ((cnf = bunny_open_configuration(file, NULL)) == NULL)
    return (false);

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

  // TOUJOURS du feu
  if (1 || (bunny_configuration_getf(cnf, &tmp, "Fire") && tmp))
    {
      assert((ing->fire = bunny_new_pixelarray(ing->map_size.x, ing->map_size.y)));
      bunny_clear(&ing->fire->clipable.buffer, 0);
    }
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

  ing->specter_map = bunny_new_picture(ing->map_size.x, ing->map_size.y);
  ing->specter_mask = bunny_new_picture(ing->map_size.x, ing->map_size.y);
  bunny_clear(&ing->specter_map->buffer, 0);
  bunny_clear(&ing->specter_mask->buffer, ALPHA(255 - 64, WHITE));
  
  size_t		size = ing->map_size.x * ing->map_size.y;

  ing->attack_map = bunny_new_bitfield(size);
  ing->build_map = bunny_new_bitfield(size);
  ing->water_map[0] = bunny_new_bitfield(size);
  ing->water_map[1] = bunny_new_bitfield(size);
  ing->current_water_map = 0;
  memset(ing->attack_map, 0, ceil(size / 8));
  memset(ing->build_map, 0, ceil(size / 8));
  memset(ing->water_map[0], 0, ceil(size / 8));
  memset(ing->water_map[1], 0, ceil(size / 8));

  assert((ing->physic_map = malloc(sizeof(t_element) * size)));
  t_bunny_color		color;
  size_t		i;
  t_bunny_position	pos;

  ing->player = NULL;
  for (i = 0; i < size; i++)
    {
      color.full = ((unsigned int*)(physic_map->pixels))[i];
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
	{
	  //// WATER
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  BITSET(ing->water_map[ing->current_water_map], pos.x, pos.y, ing->map_size.x);
	  ing->physic_map[i] = AIR;
	}
      else if (color.full == RED)
	ing->physic_map[i] = EXPLODE;
      else if (color.full == YELLOW)
	ing->physic_map[i] = SAND;
      
      else if (color.full == PINK2)
	ing->physic_map[i] = FIRE;
      
      else if (color.full == (TO_BLUE(128) | BLACK))
	ing->physic_map[i] = WATER_SOURCE;
      
      else if (color.full == (TO_BLUE(64) | BLACK))
	ing->physic_map[i] = WATER_WALL;
      
      else if (color.full == (TO_BLUE(255) | TO_RED(128) | TO_GREEN(128) | BLACK))
	ing->physic_map[i] = WATER_DEATH;
      
      else if (color.full == (TO_RED(128) | BLACK))
	ing->physic_map[i] = VICTORY;
      
      else if (color.full == (unsigned int)GRAY(64))
	ing->physic_map[i] = DEATH;
      else
	ing->physic_map[i] = AIR;
      
      if (color.full == TEAL && ing->player == NULL)
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
      else if (color.full == PINK)
	{
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ingame_new_unit(ing, WALLSPIDER, pos);
	}
      else if (color.full == (TO_GREEN(128) | BLACK))
	{
	  pos.x = i % ing->map_size.x;
	  pos.y = i / ing->map_size.x;
	  ingame_new_unit(ing, BADSPIDER, pos);
	}
    }
  assert((ing->player != NULL));
  bunny_delete_clipable(&physic_map->clipable);
  bunny_delete_configuration(cnf);
  return (true);
}

