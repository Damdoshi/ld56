#ifndef				__movement_H__

# define			__movement_H__

# define MIN_PIXEL_TO_HOLD	1

# define COEF_CLIMBING_HEIGHT	5

# include			<lapin.h>

# include			"load_file.h"
# include			"ingame.h"

void				pixel_move(t_unit			*unit,
					   t_bunny_accurate_position	target_pos,
					   t_map			*env);

#endif //			__movement_H__
