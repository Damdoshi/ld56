// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2023
//
// Allan

#include		<lapin.h>
#include		<ctype.h>

void			gpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	pos,
				 unsigned int		color)
{
  t_color		res;
  t_color		ori;
  t_color		lay;
  double		under_ratio;
  double		upper_ratio;
  int			i;

  if (pos.x >= pix->clipable.buffer.width ||
      pos.y >= pix->clipable.buffer.height ||
      pos.x < 0 || pos.y < 0)
    return ;
  lay.full = color;
  if (lay.argb[ALPHA_CMP] == 255)
    ((unsigned int*)pix->pixels)[pos.x + pos.y * pix->clipable.buffer.width] = color;
  else
    {
      res.full = 0;
      ori.full = ((unsigned int*)pix->pixels)[pos.x + pos.y * pix->clipable.buffer.width];

      upper_ratio = (double)lay.argb[ALPHA_CMP] / 255.0;
      under_ratio = (double)(255 - lay.argb[ALPHA_CMP]) / 255.0;

      res.argb[ALPHA_CMP] = 255;
      for (i = RED_CMP; i < ALPHA_CMP; ++i)
	res.argb[i] = ori.argb[i] * under_ratio + lay.argb[i] * upper_ratio;

      ((unsigned int*)pix->pixels)[pos.x + pos.y * pix->clipable.buffer.width] = res.full;
    }
}


static void		color_coef(t_color					*color,
				   const t_color				*from,
				   const t_color				*to,
				   int						cursor,
				   int						length)
{
  int			i;

  for (i = RED_CMP; i < ALPHA_CMP + 1; ++i)
    {
      double		coef;

      coef = (to->argb[i] - from->argb[i]) / (double)length;
      color->argb[i] = from->argb[i] + cursor * coef;
    }
}

static void		draw_line(t_bunny_pixelarray				*pix,
				  const t_bunny_position			*a,
				  const t_bunny_position			*b,
				  const t_color					*cola,
				  const t_color					*colb)
{
  t_color		color;
  t_bunny_position	pos;
  double		coef;
  double		i;
  int			direction;

  direction = b->x - a->x;
  if (b->x - a->x == 0 || (coef = (double)(b->y - a->y) / direction) > 1 || coef < -1)
    {
      if ((direction = b->y - a->y) == 0)
	{
	  gpixel(pix, *a, cola->full);
	  return ;
	}
      coef = (double)(b->x - a->x) / direction;
      for (i = a->y; i != b->y; i += (direction > 0) ? 1 : -1)
	{
	  color_coef(&color, cola, colb, i - a->y, direction);
	  pos.x = coef * (i - a->y) + a->x;
	  pos.y = i;
	  gpixel(pix, pos, color.full);
	}
    }
  else
    for (i = a->x; i != b->x; i += (direction > 0) ? 1 : -1)
      {
	color_coef(&color, cola, colb, i - a->x, direction);
	pos.x = i;
	pos.y = coef * (i - a->x) + a->y;
	gpixel(pix, pos, color.full);
      }
}

void			gline(t_bunny_pixelarray		*pix,
			      const t_bunny_position		*pos,
			      const unsigned int		*color)
{
  draw_line(pix, &pos[0], &pos[1], (t_color*)&color[0], (t_color*)&color[1]);
}


static void		draw_line2(float						*tab,
				   int						w,
				   int						h,
				   const t_bunny_position			*a,
				   const t_bunny_position			*b,
				   float						val)
{
  t_bunny_position	pos;
  double		coef;
  double		i;
  int			direction;

  (void)h;
  direction = b->x - a->x;
  if (b->x - a->x == 0 || (coef = (double)(b->y - a->y) / direction) > 1 || coef < -1)
    {
      if ((direction = b->y - a->y) == 0)
	{
	  if (a->x >= 0 && a->x < w && a->y >= 0 && a->y < h)
	    tab[a->x + a->y * w] = val + rand() % 50 - 25;
	  return ;
	}
      coef = (double)(b->x - a->x) / direction;
      for (i = a->y; i != b->y; i += (direction > 0) ? 1 : -1)
	{
	  pos.x = coef * (i - a->y) + a->x;
	  pos.y = i;
	  if (pos.x >= 0 && pos.x < w && pos.y >= 0 && pos.y < h)
	    tab[pos.x + pos.y * w] = val + rand() % 50 - 25;
	}
    }
  else
    for (i = a->x; i != b->x; i += (direction > 0) ? 1 : -1)
      {
	pos.x = i;
	pos.y = coef * (i - a->x) + a->y;
	if (pos.x >= 0 && pos.x < w && pos.y >= 0 && pos.y < h)
	  tab[pos.x + pos.y * w] = val + (rand() % (int)val / 2) - val / 4;
      }
}

void			dline(float				*tab,
			      int				w,
			      int				h,
			      const t_bunny_position		*pos,
			      float				val)
{
  draw_line2(tab, w, h, &pos[0], &pos[1], val);
}

typedef struct s_prog
{
  t_bunny_pixelarray *pix;
  t_bunny_window *win;
  int		w;
  int		h;
  int		len;
  float		prog;
  bool		clicked;
  t_bunny_position pos[2];
  double	rx;
  double	ry;
  double	rz;
  double	grx;
  double	gry;
  double	grz;
  double	py;
  double	sy;
  double	px;
  double	sx;
  int		step;

  t_bunny_position siz;
}		t_prog;

static t_prog	p;
t_bunny_color	col[256 * 3 + 1];
float		*pic;
float		*opic;

void			set_fire_pixel(int			x,
				       int			y)
{
  if (pic && y < p.h && y >= 0 && x >= 0 && x < p.w)
    pic[x + y * p.w] = 0 + rand() % 50 - 25;
}

void			big_reset(t_prog *p)
{
  if (p->sx > 1.0)
    {
      if (fabs(1.0 - (p->sx *= 0.9)) < 0.001)
	p->sx = 1.0;
    }
  else if (p->sx < 1.0)
    {
      if (fabs(1.0 - (p->sx *= 1.1)) < 0.001)
	p->sx = 1.0;
    }
  if (p->sy > 1.0)
    {
      if (fabs(1.0 - (p->sy *= 0.9)) < 0.001)
	p->sy = 1.0;
    }
  else if (p->sy < 1.0)
    {
      if (fabs(1.0 - (p->sy *= 1.1)) < 0.001)
	p->sy = 1.0;
    }

  if (p->px > 0)
    p->px -= 1;
  else if (p->px < 0)
    p->px += 1;

  if (p->py > 0)
    p->py -= 1;
  else if (p->py < 0)
    p->py += 1;

  if ((int)p->rx % 360 != 0)
    p->rx += 1;
  else
    p->rx = 0;
  if ((int)p->ry % 360 != 0)
    p->ry += 1;
  else
    p->ry = 0;
  if ((int)p->rz % 360 != 0)
    p->rz += 1;
  else
    p->rz = 0;
  if ((int)p->grx % 360 != 0)
    p->grx += 1;
  else
    p->grx = 0;
  if ((int)p->gry % 360 != 0)
    p->gry += 1;
  else
    p->gry = 0;
  if ((int)p->grz % 360 != 0)
    p->grz += 1;
  else
    p->grz = 0;
}

static void		rotate(t_bunny_position	*pos,
			       double		grotx,
			       double		groty,
			       double		grotz)
{
  double		rotx, roty, rotz;
  double		x, y, z;
  double		xx, yy, zz;

  rotx = M_PI * grotx / 180.0;
  roty = M_PI * groty / 180.0;
  rotz = M_PI * grotz / 180.0;

  x = pos->x;
  y = pos->y;
  z = 0;

  xx = x * 1 + y * 0 + z * 0;
  yy = x * 0 + y * cos(rotx) - z * sin(rotx);
  zz = x * 0 + y * sin(rotx) + z * cos(rotx);

  x = xx * cos(roty) + yy * 0 + zz * sin(roty);
  y = xx * 0 + yy * 1 - zz * 0;
  z = -xx * sin(roty) + yy * 0 + zz * cos(roty);

  xx = x * cos(rotz) - y * sin(rotz) + z * 0;
  yy = x * sin(rotz) + y * cos(rotz) - z * 0;
  zz = x * 0 + y * 0 + z * 1;

  pos->x = xx;
  pos->y = yy;
}

t_bunny_response display(void		*n,
			 bool		underfire)
{
  static int prog;
  t_prog *p = (t_prog*)n;
  int i;
  int j;

  // Du bruit en bas
  if (underfire)
    {
      for (j = 0; j < 2; ++j)
	for (i = 0; i < p->w; ++i)
	  {
	    if (rand() % 2 == 0)
	      pic[i + (j + p->h) * p->w] = rand() % 64;
	    else
	      pic[i + (j + p->h) * p->w] = NBRCELL(col) - 1;// / 1.2;
	  }
    }
  else
    {
      for (j = 0; j < 2; ++j)
	for (i = 0; i < p->w; ++i)
	  opic[i + (j + p->h) * p->w] = pic[i + (j + p->h) * p->w] = NBRCELL(col) - 1;// / 1.2;
    }

  // La moyenne des blocs
  for (j = p->h + 1; j >= 0; --j)
    for (i = 0; i < p->w; ++i)
      {
	float sum = 0;

	if (i == 0)
	  {
	    sum += pic[(p->w - 1) + (j + 0) * p->w];
	    sum += pic[(p->w - 1) + (j + 1) * p->w];
	  }
	else
	  {
	    sum += pic[(i - 1) + (j + 0) * p->w];
	    sum += pic[(i - 1) + (j + 1) * p->w];
	  }

	if (i == p->w - 1)
	  {
	    sum += pic[(0 + 0) + (j + 0) * p->w];
	    sum += pic[(0 + 0) + (j + 1) * p->w];
	  }
	else
	  {
	    sum += pic[(i + 1) + (j + 0) * p->w];
	    if (i + 1 + (j + 1) * p->w < p->w * p->h)
	      sum += pic[(i + 1) + (j + 1) * p->w];
	  }

	sum += pic[(i + 0) + (j + 0) * p->w];
	sum += pic[(i + 0) + (j + 1) * p->w];
	if (rand() % (int)(40 * (1.0 / p->prog)) == 0)
	  sum = 99999;
	else
	  sum /= 6.0;
	int acc = (i + 0) + (j - 1) * p->w;

	if (acc > 0 && acc < p->w * (p->h + 2))
	  {
	    if (sum + p->prog >= NBRCELL(col)) // Si on depasse, on met du noir
	      opic[acc] = NBRCELL(col) - 1;
	    else
	      opic[acc] = (int)sum + p->prog; // On progresse quand meme.
	  }
      }

  // Maintenant, on renvoit les resultats
  for (i = 0; i < p->len; ++i)
    {
      if ((pic[i] = opic[i]) >= 0)
	((unsigned int*)p->pix->pixels)[i] = col[(int)opic[i]].full;
      else
	((unsigned int*)p->pix->pixels)[i] = col[0].full;
    }

  // Lissage des pixels noirs
  for (i = 0; i < p->len && 0; ++i)
    {
      t_bunny_color col = {.full = ((unsigned int*)p->pix->pixels)[i] };
      int x = i % p->w;
      int y = i / p->w;

      col.argb[ALPHA_CMP] = 0;
      if (col.full == 0)
	{
	  t_bunny_color left;
	  t_bunny_color right;
	  int z;

	  if (x != 0)
	    left.full = ((unsigned int*)p->pix->pixels)[x - 1 + y * p->w];
	  else
	    left.full = ((unsigned int*)p->pix->pixels)[p->w - 1 + y * p->w];
	  if (x < p->w - 1)
	    right.full = ((unsigned int*)p->pix->pixels)[x + 1 + y * p->w];
	  else
	    right.full = ((unsigned int*)p->pix->pixels)[0 + y * p->w];

	  for (z = 0; z < 4; ++z)
	    col.argb[z] = ((int)left.argb[z] + (int)right.argb[z]) / 2;
	  col.argb[ALPHA_CMP] = 255;
	  ((unsigned int*)p->pix->pixels)[i] = col.full;
	}
    }
  const char *str = " efrits ";
  size_t len = strlen(str) - 1;
  t_bunny_position siz;

  siz.x = p->pix->clipable.buffer.width / len;
  siz.y = p->pix->clipable.buffer.height * 0.1;
  p->siz = siz;

  int step;
  int  cnt;

  cnt = 0;
  if (p->step / 300 == 1)
    step = (p->step % 300);
  else
    step = 99999;

  for (int l = 0; str[l] && p->step / 300 != 0 && cnt < step / 10; ++l)
    {
      const t_bunny_letter *let;
      t_bunny_letter cpy;

      if (isalpha(str[l]))
	let = &gl_vector_font[str[l] - 'a' + BFT_A];
      else if (isdigit(str[l]))
	let = &gl_vector_font[str[l] - '0' + BFT_0];
      else
	continue ;
      memcpy(&cpy, let, sizeof(cpy));
      for (int e = 0; e < cpy.nb_edge && cnt < step / 10; ++e)
	{
	  t_bunny_position pos[2] =
	    {
	     {cpy.edge[e].x0 - 10, cpy.edge[e].y0 - 10},
	     {cpy.edge[e].x1 - 10, cpy.edge[e].y1 - 10}
	    };
	  //unsigned int	cl[2] = {WHITE, RED};

	  if (cnt + 1 >= step / 10)
	    {
	      double prog = (step % 10) / 10.0;

	      pos[1].x = (pos[1].x - pos[0].x) * prog + pos[0].x;
	      pos[1].y = (pos[1].y - pos[0].y) * prog + pos[0].y;
	    }

	  for (int s = 0; s < 2; ++s)
	    {
	      // On tourne la lettre seule
	      rotate(&pos[s], p->rx, p->ry, p->rz);

	      // On scale
	      pos[s].x = (pos[s].x / 20.0) * siz.x * p->sx;
	      pos[s].y = (pos[s].y / 20.0) * siz.y * p->sy;

	      // On translate vers un repere propre au mot
	      pos[s].x += -(siz.x * len / 2.0) + l * siz.x;
	      pos[s].y += 0;

	      // On tourne le mot entier
	      rotate(&pos[s], p->grx, p->gry, p->grz);

	      // On translate vers l'ecran
	      pos[s].x += p->pix->clipable.buffer.width / 2 + p->px;
	      pos[s].y += p->pix->clipable.buffer.height * 0.5 + p->py;

	    }
	  // gline(p->pix, &pos[0], &cl[0]);
	  dline(pic, p->w, p->h, &pos[0], 200);
	  cnt += 1;
	}
    }

  double d = cos(prog++ / 50.0) * 128;

  if (d < 0)
    d = 0;
  p->pix->clipable.color_mask.argb[ALPHA_CMP] = 255;// 16 + d;
  return (GO_ON);
}

t_bunny_response loop(void		*n)
{
  t_prog *p = (t_prog*)n;

  /*
  switch (p->step / 300)
    {
    case 0:
    case 1:
      break ;
    case 2:
      p->grx += 3;
      p->gry += 2;
      p->grz += 1;
      break ;
    case 3:
      if ((int)p->grx % 360 != 0)
	p->grx += 3;
      else
	p->grx = 0;
      if ((int)p->gry % 360 != 0)
	p->gry += 2;
      else
	p->gry = 0;
      if ((int)p->grz % 360 != 0)
	p->grz += 1;
      else
	p->grz = 0;
      p->ry += 3 + (300.0 - (p->step % 300)) / 30.0;
      break ;
    case 4:
      if ((int)p->ry % 360 != 0)
	p->ry += 3;
      else
	p->ry = 0;
      p->rx += 3;
      p->rz += 2;
      break ;
    case 5:
      if ((int)p->rz % 360 != 0)
	p->rz += 3;
      else
	p->rz = 0;
      p->rx += 3;
      p->gry += 4;
      break ;
    case 6:
    case 7:
      big_reset(p);
      if (p->rx == 0 && p->ry == 0 && p->rz == 0 && p->grx == 0 && p->gry == 0 && p->grz == 0)
	p->step = 0;
      break ;
    }
  */
  p->step += 1;
  return (GO_ON);
}


int		fire(t_bunny_pixelarray		*px,
		     bool			underfire)
{
  int j;
  int i;

  p.pix = px;

  if (px == NULL)
    {
      free(pic);
      free(opic);
      pic = NULL;
      opic = NULL;
      return (0);
    }

  p.clicked = GO_UP;
  p.prog = 3;
  p.sx = 1.0;
  p.sy = 1.0;
  p.px = 0;
  p.py = 0;
  p.step = 0;
  p.w = px->clipable.buffer.width;
  p.h = px->clipable.buffer.height;
  p.len = p.w * p.h;

  if (!pic)
    {
      pic = (float*)calloc(1, (p.w * (p.h + 5)) * sizeof(*pic)); // C'est + 2 normalement
      opic = (float*)calloc(1, (p.w * (p.h + 5)) * sizeof(*opic));
      j = 0;
      if (!underfire || 1) // EFRITS
	{
	  for (i = 0; i < 256; ++i)
	    col[j++].full = TO_GREEN(255) | TO_BLUE(255 - i) | TO_RED(255) | BLACK;
	  for (i = 0; i < 256; ++i)
	    col[j++].full = TO_GREEN(255 - i) | TO_RED(255) | BLACK;
	  for (i = 0; i < 256; ++i)
	    col[j++].full = TO_RED(255 - i) | TO_ALPHA(255 - i);
	  col[j++].full = 0;
	  for (i = 0; i < p.w * (p.h + 5); ++i)
	    opic[i] = pic[i] = NBRCELL(col) - 1;
	}
      else
	{
	  for (i = 0; i < 256; ++i)
	    col[j++].full = TO_GREEN(255) | TO_BLUE(255) | TO_RED(255 - i) | BLACK;
	  for (i = 0; i < 256; ++i)
	    col[j++].full = TO_GREEN(255) | TO_BLUE(255 - i) | BLACK;
	  for (i = 0; i < 256; ++i)
	    col[j++].full = TO_GREEN(255 - i) | BLACK;
	  col[j++].full = BLACK;
	  for (i = 0; i < p.w * (p.h + 5); ++i)
	    opic[i] = pic[i] = NBRCELL(col) - 1;
	}
    }

  loop(&p);
  display(&p, underfire);

  return (0);
}
