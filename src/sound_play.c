
#include		"program.h"

void			sound_play(t_bunny_effect	*eff)
{
  if (eff && !bunny_sound_is_playing(&eff->sound))
    bunny_sound_play(&eff->sound);
}

