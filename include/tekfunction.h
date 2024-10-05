/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2016
**
** TekFunction
*/

#ifndef			__TEKFUNCTION_H__
# define		__TEKFUNCTION_H__
# include		<lapin.h>

void			tektext(t_bunny_pixelarray			*out,
				t_bunny_pixelarray			*font,
				const t_bunny_position			*pos,
				const char				*str);
void			tekblit(t_bunny_pixelarray			*out,
				const t_bunny_pixelarray		*in,
				const t_bunny_position			*pos);
void			tekclear(t_bunny_pixelarray			*pix,
				 unsigned int				color);
void			tekfill(t_bunny_pixelarray			*pix,
				unsigned int				color);
void			tekline(t_bunny_pixelarray			*pix,
				const t_bunny_position			*pos,
				const unsigned int			*color);
void			tekpixel(t_bunny_pixelarray			*pix,
				 const t_bunny_position			pos,
				 unsigned int				color);
void			tekinit(void);

#endif	/*		__TEKFUNCTION_H__	*/

