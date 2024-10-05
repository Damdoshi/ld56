// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

t_bunny_response	main_menu_loop(t_main_menu		*main_menu)
{
  t_bunny_position	pos_mou = get_real_mouse_position(main_menu->program->screen);
  t_bunny_area		area[2] =
    {
      {
	main_menu->text_menu[0]->clipable.position.x,
	main_menu->text_menu[0]->clipable.position.y,
	main_menu->text_menu[0]->clipable.buffer.width,
	main_menu->text_menu[0]->clipable.buffer.height
      },
      {
	main_menu->text_menu[1]->clipable.position.x,
	main_menu->text_menu[1]->clipable.position.y,
	main_menu->text_menu[1]->clipable.buffer.width,
	main_menu->text_menu[1]->clipable.buffer.height
      }
    };

  if (pos_mou.x >= area[0].x
      && pos_mou.x <= area[0].x + area[0].w
      && pos_mou.y >= area[0].y
      && pos_mou.y <= area[0].y + area[0].h)
    {
      printf("position x = %d, y = %d de la souris\n", pos_mou.x, pos_mou.y);
      main_menu->text_menu[0]->clipable.color_mask.full = BLACK | rand();
    }
  else if (area[1].x <= pos_mou.x
	   && area[1].x + area[1].w >= pos_mou.x
	   && area[1].y <= pos_mou.y
	   && area[1].y + area[1].h >= pos_mou.y)
    {
      printf("position x = %d, y = %d de la souris\n", pos_mou.x, pos_mou.y);
      main_menu->text_menu[1]->clipable.color_mask.full = BLACK | rand();
    }
  else
    {
      main_menu->text_menu[0]->clipable.color_mask.full = WHITE;
      main_menu->text_menu[1]->clipable.color_mask.full = WHITE;
    }
  (void)main_menu;
  return (GO_ON);
}

