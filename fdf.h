/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:29:49 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/12/28 14:31:16 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define WIDTH (2550)
# define HEIGHT (1300)
# define SHIFT (500)
# define ABS(a) ((a < 0) ? (-(a)) : (a))
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include "fdf.h"
# include "get_next_line.h"
# include <string.h>

typedef struct		s_pt
{
	double			x;
	double			y;
	double			z;
	double			x_2d;
	double			y_2d;
}					t_pt;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_pt			**grid;
	char			*table;
	int				width;
	int				height;
	int				bpp;
	int				size;
	int				endian;
	int				z_min;
	int				z_max;
	double			zoom;
	int				y;
	int				r;
	int				g;
	int				b;
	int				p;
	int				c;
}					t_env;

void				*ft_xmalloc(size_t size);
void				ft_error(char *s);

void				ft_center(t_env *e, float x_shift, float y_shift,
															float z_shift);
void				ft_draw(t_env *e);
void				ft_putpixel(int x, int y, t_env *e);
void				ft_drawline(t_pt *a, t_pt *b, t_env *e);

int					ft_exposehook(t_env *e);
int					ft_keypress(int keycode, t_env *e);

int					ft_atoi(const char *str);
void				ft_putendl_fd(char const *s, int fd);
char				**ft_strsplit(char const *s, char c);

void				ft_colorchoice(t_env *e, int keycode);
void				ft_colorchoice2(t_env *e, int keycode);
void				ft_colorchoice3(t_env *e, int keycode);

void				ft_fillimg(t_env *e);
void				ft_transform(t_env *e);
void				ft_swapptr(t_pt **a, t_pt **b);
void				ft_draw_first_case(t_pt *a, t_pt *b, t_env *e);
void				ft_draw_second_case(t_pt *a, t_pt *b, t_env *e);
#endif
