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
  if (main_menu->program->context != MAIN_MENU)
    {
      main_menu->program->ingame.current_level = 0;
      return (SWITCH_CONTEXT);
    }
  
  main_menu->text_menu[0]->color = BLACK | TO_RED(128);
  main_menu->text_menu[1]->color = BLACK | TO_RED(128);

  if (main_menu->delay < bunny_get_current_time())
    {
      if (pos_mou.x >= area[0].x
	  && pos_mou.x <= area[0].x + area[0].w
	  && pos_mou.y >= area[0].y
	  && pos_mou.y <= area[0].y + area[0].h)
	main_menu->text_menu[0]->color = WHITE;
      else if (area[1].x <= pos_mou.x
	       && area[1].x + area[1].w >= pos_mou.x
	       && area[1].y <= pos_mou.y
	       && area[1].y + area[1].h >= pos_mou.y)
	main_menu->text_menu[1]->color = WHITE;
    }
  
  bunny_sprite_animate_now(main_menu->cursor);
  return (GO_ON);
}

