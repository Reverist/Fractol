/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:22:45 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 20:26:49 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_iter(t_fractol *f)
{
	f->i.y = 0;
	while (f->i.y++ < WIN_HEIGHT)
	{
		f->i.x = 0;
		while (f->i.x++ < WIN_WIDTH)
			draw_frac(f);
	}
}

void	brot(t_fractol *f, int *i)
{
	double	nbr;

	init_complex(f);
	nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	while ((*i)++ < f->maxiter && nbr < 4)
	{
		f->old.re = f->new.re;
		f->old.im = f->new.im;
		f->new.re = f->old.re * f->old.re - f->old.im * f->old.im + f->c.re;
		f->new.im = 2 * f->old.re * f->old.im + f->c.im;
		nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	}
}

void	cubic_ship(t_fractol *f, int *i)
{
	double	nbr;

	init_complex(f);
	nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	while ((*i)++ < f->maxiter && nbr < 4)
	{
		f->old.re = f->new.re;
		f->old.im = f->new.im;
		f->new.re = (mult(f->old.re) - (mult(f->old.im) * 3.0))
			* fabs(f->old.re) + f->c.re;
		f->new.im = ((mult(f->old.re) * 3) - mult(f->old.im))
			* fabs(f->old.im) + f->c.im;
		nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	}
}

void	set_pixel(t_fractol *f, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		*(int *)&f->w.ptr[(x * f->w.bits_per_pixel) +
			(y * f->w.size_line)] = color;
}

void	draw_frac(t_fractol *f)
{
	int j;

	j = 0;
	f->c.re = 1.5 * (f->i.x - WIN_WIDTH / 2) /
		(0.5 * f->zoom * WIN_WIDTH) + f->move_x;
	f->c.im = (f->i.y - WIN_HEIGHT / 2) /
		(0.5 * f->zoom * WIN_HEIGHT) + f->move_y;
	if (!ft_strcmp(f->fractal, "Mandelbrot"))
		brot(f, &j);
	if (!ft_strcmp(f->fractal, "Cubic_ship"))
		cubic_ship(f, &j);
	if (!ft_strcmp(f->fractal, "Tricorn"))
		mand_tricorn(f, &j);
	if (!ft_strcmp(f->fractal, "V_mandelbrot"))
		v_mand(f, &j);
	if (!ft_strcmp(f->fractal, "Celtic_heart"))
		celcit_heart(f, &j);
	set_pixel(f, f->i.x, f->i.y, color(f, j));
}
