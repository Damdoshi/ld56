// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"main_menu.h"

t_bunny_response	main_menu_display(t_main_menu	*main_menu)
{
  fire(main_menu->fire, false, NULL);
  bunny_clear(&main_menu->text_menu[0]->clipable.buffer, 0);
  bunny_draw(&main_menu->text_menu[0]->clipable);
  bunny_blit(&main_menu->text->clipable.buffer, &main_menu->text_menu[0]->clipable, NULL);

  bunny_clear(&main_menu->text_menu[1]->clipable.buffer, 0);
  bunny_draw(&main_menu->text_menu[1]->clipable);
  bunny_blit(&main_menu->text->clipable.buffer, &main_menu->text_menu[1]->clipable, NULL);

  bunny_blit(&main_menu->program->screen->buffer, main_menu->menu, NULL);
  double now = bunny_get_current_time();

  if (main_menu->delay < now)
    {
      if (main_menu->title->color_mask.argb[ALPHA_CMP] < 130)
	main_menu->title->color_mask.argb[ALPHA_CMP] += 1;
      else if (main_menu->title->color_mask.argb[ALPHA_CMP] < 255)
	main_menu->title->color_mask.argb[ALPHA_CMP] += 5;
      else
	{
	  bunny_blit(&main_menu->program->screen->buffer, &main_menu->text->clipable, NULL); 
	  for (ssize_t j = 0; j < main_menu->fire->clipable.buffer.height; ++j)
	    for (ssize_t i = 0; i < main_menu->fire->clipable.buffer.width; ++i)
	      if (((unsigned int*)main_menu->text->pixels)[i + j * main_menu->text->clipable.buffer.width] == WHITE)
		set_fire_pixel(i, j);
	  main_menu->fire->clipable.color_mask.argb[ALPHA_CMP] = 255;
	  if (main_menu->delay < now)
	    bunny_blit(&main_menu->program->screen->buffer, &main_menu->fire->clipable, NULL);
	}
    }

  bunny_blit(&main_menu->program->screen->buffer, main_menu->title, NULL);

  t_bunny_position	pos = get_real_mouse_position(main_menu->program->screen);

  main_menu->cursor->clipable.position.x = pos.x;
  main_menu->cursor->clipable.position.y = pos.y;
  bunny_blit(&main_menu->program->screen->buffer, &main_menu->cursor->clipable, NULL);

  bunny_blit(&main_menu->program->window->buffer, main_menu->program->screen, NULL);

  if (main_menu->delay - 2 > now)
    bunny_clear(&main_menu->program->window->buffer, BLACK);
  else if (main_menu->delay > now)
    {
      double ratio = 255 * (main_menu->delay - now) / 2.0;

      bunny_fill(&main_menu->program->window->buffer, ALPHA((int)ratio, BLACK));
    }
  
  bunny_display(main_menu->program->window);
  return (GO_ON);
}

