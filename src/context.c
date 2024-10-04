// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2024
// EFRITS SAS 2022-2024
// Pentacle Technologie 2008-2024
//
// Game

#include		<lapin.h>
#include		"program.h"
#include		"context_declaration.template"

t_bunny_context		gl_context[LAST_CONTEXT] =
  {
    [INGAME] = { bunny_fill_context(ingame) },
    [MAIN_MENU] = { bunny_fill_context(main_menu) },
    [CINEMATIC] = { bunny_fill_context(cinematic) }
  };

