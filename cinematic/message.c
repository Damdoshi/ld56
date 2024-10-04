// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		"program.h"
#include		"cinematic.h"

t_bunny_response	cinematic_message(int		fd,
					const void	*buffer,
					size_t		size,
					t_cinematic	*cinematic)
{
  (void)fd;
  (void)buffer;
  (void)size;
  (void)cinematic;
  return (GO_ON);
}

