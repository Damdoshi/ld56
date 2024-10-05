#ifndef				__BUTCHER_H__
#define				__BUTCHER_H_

typedef struct s_deltimer
{
  int timer; /// destroy at frame X
  t_bunny_position pos;
}t_deltimer;
typedef struct s_deletelist
{
  int len; //ammount of timers inside the list
  t_deltimer *list;
}t_deletelist;

#endif	/*			__BUTCHER_H__		*/
