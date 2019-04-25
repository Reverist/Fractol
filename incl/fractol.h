/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:35:26 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 21:47:39 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <limits.h>
# include <math.h>
# include <float.h>
# include "../libft/libft.h"
# include "keyh.h"
# define PI						3.14159265359
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720
# define KEYPRESS				2
# define KEYRELEASE				3
# define KEYPRESSMASK			(1L << 0)
# define KEYRELEASEMASK			(1L << 1)

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct	s_rgb
{
	double red;
	double green;
	double blue;
}				t_rgb;

typedef struct	s_matrix
{
	double	x;
	double	y;
}				t_matrix;

typedef struct	s_triangle
{
	t_matrix p1;
	t_matrix p2;
	t_matrix p3;
}				t_tri;

typedef struct	s_carpet
{
	t_matrix	p1;
	t_matrix	p2;
}				t_carp;

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_window;

typedef struct	s_complex
{
	double	im;
	double	re;
}				t_complex;

typedef struct	s_mouse
{
	double	click_x;
	double	click_y;
	short	button1;
	short	button2;
}				t_mouse;

typedef struct	s_fractol
{
	t_window	w;
	double		zoom;
	double		move_x;
	double		move_y;
	int			maxiter;
	char		*fractal;
	double		depth;
	int			color;
	t_complex	new;
	t_complex	old;
	t_complex	c;
	t_point		i;
	t_carp		carp;
	t_mouse		mouse;
	t_rgb		p;
	long		max_color;
	short		psyduck;
	short		menu;
	int			menu_width;
}				t_fractol;

void			mlx(t_fractol *f);
void			new_image(t_fractol *f);
void			set_pixel(t_fractol *f, int x, int y, int color);
void			fractol(t_fractol *f);
void			zoom(t_fractol *f, int k);
int				user_hook(int k, t_fractol *f);
void			shape(t_fractol *f, int k);
int				motion_hook(int x, int y, t_fractol *f);
void			get_type(t_fractol *f, char *title);
void			iter(t_fractol *f, int k);
void			init(t_fractol *f);
void			brot(t_fractol *f, int *i);
void			translate(t_fractol *f, int k);
void			draw_frac(t_fractol *f);
void			frac_iter(t_fractol *f);
double			mult(double a);
void			cubic_ship(t_fractol *f, int *i);
void			mand_tricorn(t_fractol *f, int *i);
double			mult2(double a, double b);
void			v_mand(t_fractol *f, int *i);
void			celcit_heart(t_fractol *f, int *i);
void			drawsierpinski(t_fractol *f);
void			drawline(t_fractol *p, t_matrix p0, t_matrix p1);
void			sierp_pixel(t_fractol *p, t_matrix a, int color);
t_tri			coord(t_tri *t, int flag);
void			subtri(t_fractol *f, t_tri *t, int n);
void			draw_square(t_fractol *f, t_carp *c);
void			carpet(t_fractol *f);
void			draw_carpet(t_fractol *f, t_carp *c, int n);
t_carp			carp_point(t_carp *c, int flag);
int				mouse_move(int x, int y, t_fractol *f);
void			mouse_zoom(int k, t_fractol *f, int x, int y);
int				wheel_hook(int b, int x, int y, t_fractol *f);
unsigned int	color(t_fractol *f, int iter);
unsigned int	set_color(unsigned int r, unsigned int g, unsigned int b);
void			psycho(t_fractol *f);
void			error(char *str);
void			menu(t_fractol *f);
void			menu_hook(t_fractol *f, int k);
void			menu_display(t_window *w, unsigned c);
void			init_complex(t_fractol *f);
t_tri			coords(t_tri *t, int flag);
t_carp			poits_carp(t_carp *c, int flag);
void			julia_iter(t_fractol *f, int *j);
#endif
