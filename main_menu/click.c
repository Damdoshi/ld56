// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"main_menu.h"

t_bunny_response		main_menu_click(t_bunny_event_state	state,
					      t_bunny_mouse_button	but,
					      t_main_menu			*main_menu)
{
  if (but != BMB_LEFT)
    return (GO_ON);
  if (state == GO_DOWN)
    {
      t_bunny_position pos_mou = get_real_mouse_position(main_menu->program->screen);
      if (main_menu->pos_txt[0].x <= pos_mou.x
	  && main_menu->pos_txt[0].x + main_menu->pos_txt[0].w >= pos_mou.x
	  && main_menu->pos_txt[0].y <= pos_mou.y
	  && main_menu->pos_txt[0].y + main_menu->pos_txt[0].h >= pos_mou.y)
	{
	  main_menu->text_menu[0]->clipable.color_mask.full = BLACK;
	  main_menu->text_menu[0]->clipable.color_mask.argb[0] = 100;
	  main_menu->program->context = GAME;
	  return (SWITCH_CONTEXT);
	}
      else if (main_menu->pos_txt[1].x <= pos_mou.x
	       && main_menu->pos_txt[1].x + main_menu->pos_txt[1].w >= pos_mou.x
	       && main_menu->pos_txt[1].y <= pos_mou.y
	       && main_menu->pos_txt[1].y + main_menu->pos_txt[1].h >= pos_mou.y)
	{
	  main_menu->text_menu[1]->clipable.color_mask.full = BLACK;
	  main_menu->text_menu[1]->clipable.color_mask.argb[0] = 100;
	  return (EXIT_ON_SUCCESS);
	}
    }
  (void)state;
  (void)but;
  (void)main_menu;
  return (GO_ON);
}

