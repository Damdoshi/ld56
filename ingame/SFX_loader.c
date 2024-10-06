#include "program.h"

void sfx_loader(t_ingame *ing)
{
  int i = 0;
  int j = 0;
  int c[5];
  ing->sfx[PLAYER][0] = bunny_load_effect("res/SFX/player/small_dmg.ogg");
  ing->sfx[PLAYER][1] = bunny_load_effect("res/SFX/player/medium_dmg.ogg");
  ing->sfx[PLAYER][2] = bunny_load_effect("res/SFX/player/medium_dmg2.ogg");
  ing->sfx[PLAYER][3] = bunny_load_effect("res/SFX/player/medium_dmg3.ogg");
  ing->sfx[PLAYER][4] = bunny_load_effect("res/SFX/player/big_dmg.ogg");
  ing->sfx[PLAYER][5] = bunny_load_effect("res/SFX/player/death.ogg");
  ing->sfx[PLAYER][6] = bunny_load_effect("res/SFX/player/burning.ogg");
  ing->sfx[PLAYER][7] = bunny_load_effect("res/SFX/player/degaine.ogg");
  ing->sfx[PLAYER][8] = bunny_load_effect("res/SFX/player/incantation.ogg");
  ing->sfx[PLAYER][9] = bunny_load_effect("res/SFX/player/idle.ogg");
  ing->sfx[PLAYER][10] = bunny_load_effect("res/SFX/player/baillement.ogg");
  ing->sfx[PLAYER][11] = bunny_load_effect("res/SFX/player/pas1.ogg");
  ing->sfx[PLAYER][12] = bunny_load_effect("res/SFX/player/pas2.ogg");
  ing->sfx[PLAYER][13] = bunny_load_effect("res/SFX/player/pas3.ogg");
  ing->sfx[PLAYER][14] = bunny_load_effect("res/SFX/player/pas4.ogg");
  ing->sfx[PLAYER][15] = bunny_load_effect("res/SFX/player/pas5.ogg");
  ing->sfx[PLAYER][16] = bunny_load_effect("res/SFX/player/water_step.ogg");
  ing->sfx[PLAYER][17] = bunny_load_effect("res/SFX/player/fall_in_water.ogg");
  ing->sfx[PLAYER][18] = bunny_load_effect("res/SFX/player/jump_end.ogg");
  ing->sfx[PLAYER][19] = bunny_load_effect("res/SFX/player/jump_end_heavy.ogg");
  ing->sfx[PLAYER][20] = bunny_load_effect("res/SFX/player/jump.ogg");
  ing->sfx[PLAYER][21] = bunny_load_effect("res/SFX/player/jump_grunt.ogg");
  ing->sfx[PLAYER][22] = bunny_load_effect("res/SFX/player/jump_grunt2.ogg");
  c[0] = 23;

  ing->sfx[MENU][0] = bunny_load_effect("res/SFX/menu/bruitage de menu");
  c[1] = 0;

  ing->sfx[NPC][0] = bunny_load_effect("res/SFX/npc/spider_walk.ogg");
  c[2] = 1;

  ing->sfx[ENEMY_NPC][0] = bunny_load_effect("res/SFX/enemy_npc/graouh");
  c[3] = 0;

  ing->sfx[AMBIENT][0] = bunny_load_effect("res/SFX/ambient/drip1.ogg");
  ing->sfx[AMBIENT][1] = bunny_load_effect("res/SFX/ambient/drip2.ogg");
  ing->sfx[AMBIENT][2] = bunny_load_effect("res/SFX/ambient/drip3.ogg");
  ing->sfx[AMBIENT][3] = bunny_load_effect("res/SFX/ambient/water_falling.ogg");
  c[4] = 4;
  while (j < 5)
    while(i < c[j])
      {
	bunny_sound_loop(&(ing->sfx[j][i]->sound),false);
	i++;
      }
  j++;
  i = 0;
}
