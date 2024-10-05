// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"credit.h"

t_bunny_response	credit_connect(int			fd,
					t_bunny_event_state	state,
					t_credit		*credit)
{
  (void)fd;
  (void)state;
  (void)credit;
  return (GO_ON);
}

