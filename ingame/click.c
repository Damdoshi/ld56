// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include			"program.h"
#include			"ingame.h"

t_bunny_response		ingame_click(t_bunny_event_state	state,
					      t_bunny_mouse_button	but,
					      t_ingame			*ingame)
{
  if (but != BMB_LEFT && but != BMB_RIGHT)
    return (GO_ON);

  if (ingame->cursor_type == ATTACK)
    {
      if (state == GO_DOWN && but == BMB_RIGHT)
	{
	  t_bunny_position pos = get_real_mouse_position(ingame->program->screen);

	  for (size_t i = 0; i < ingame->last_unit && i < NBRCELL(ingame->units); i++)
	    if (ingame->units[i].selected && ingame->units[i].type == EATSPIDER)
	      {
		ingame->units[i].target.x = pos.x + ingame->camera.x;
		ingame->units[i].target.y = pos.y + ingame->camera.y;
	      }
	  t_bunny_position		pos_start;
	  size_t			ind[ingame->last_selection];
	  size_t			nb = 0;
	  t_unit			*unit = ingame->unit;

	  for (size_t i = 0; i < ingame->last_selection && i < NBRCELL(ingame->selection); i++)
	    {
	      if (unit[i].unit_type == EATSPIDER)
		{
		  ind[nb];
		  nb++;
		}
	    }
	  int s = (r * 2) / nb;

	  pos_start.y = kclamps(unit[ind[i]].target.y, 0, ingame->program->screen->clipable.height);
	  pos_start.x = kclamps(unit[ind[i]].target.x - r, 0, ingame->program->screen->clipable.width);

	  for (size_t i = 0; i < nb; i++)
	    {
	      ingame->selection[ind[i]].nb = 0;
	      ingame->selection[ind[i]].target_area.x = pos_start.x += s;
	      ingame->selection[ind[i]].target_area.y = pos_start.y;
	      ingame->selection[ind[i]].target_area.w = s;
	      ingame->selection[ind[i]].target_area.h = r;
	    }
	}
    }
  else if (ingame->cursor_type == SELECTION)
    {
      if (but == BMB_LEFT)
	{
	  if (state == GO_DOWN)
	    ingame_start_select(ingame);
	  else
	    ingame_end_select(ingame);
	}
      else if (but == BMB_RIGHT)
	{
	  t_bunny_position pos = get_real_mouse_position(ingame->program->screen);

	  for (size_t i = 0; i < ingame->last_unit && i < NBRCELL(ingame->units); i++)
	    if (ingame->units[i].selected)
	      {
		ingame->units[i].target.x = pos.x + ingame->camera.x;
		ingame->units[i].target.y = pos.y + ingame->camera.y;
		ingame->units[i].target_action = ingame->cursor_type;
	      }
	}
    }
  return (GO_ON);
}

