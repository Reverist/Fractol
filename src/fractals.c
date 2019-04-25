/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:33:17 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 21:13:54 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(t_fractol *f)
{
	t_point	i;
	int		j;

	i.y = 0;
	while (i.y++ < WIN_HEIGHT)
	{
		i.x = 0;
		while (i.x++ < WIN_WIDTH)
		{
			f->new.re = 1.5 * (i.x - WIN_WIDTH / 2) /
				(0.5 * f->zoom * WIN_WIDTH) + f->move_x;
			f->new.im = (i.y - WIN_HEIGHT / 2) /
				(0.5 * f->zoom * WIN_HEIGHT) + f->move_y;
			j = 0;
			julia_iter(f, &j);
			if (!(i.x < 0 || i.x >= WIN_WIDTH || i.y < 0 || i.y >= WIN_HEIGHT))
				set_pixel(f, i.x, i.y, color(f, j));
		}
	}
}

void	julia_iter(t_fractol *f, int *j)
{
	double	nbr;

	nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	while ((*j)++ < f->maxiter && nbr < 4)
	{
		f->old.re = f->new.re;
		f->old.im = f->new.im;
		f->new.re = f->old.re * f->old.re -
			f->old.im * f->old.im + f->c.re;
		f->new.im = 2 * f->old.re * f->old.im + f->c.im;
		nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	}
}

void	celcit_heart(t_fractol *f, int *i)
{
	double	nbr;

	init_complex(f);
	nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	while ((*i)++ < f->maxiter && nbr < 4)
	{
		f->old.re = f->new.re;
		f->old.im = f->new.im;
		f->new.im = fabs(f->old.re) * f->old.im * 2.0 + f->c.im;
		f->new.re = fabs(mult(f->old.re) - mult(f->old.im)) + f->c.re;
		nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	}
}

void	v_mand(t_fractol *f, int *i)
{
	double	nbr;

	init_complex(f);
	nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	while ((*i)++ < f->maxiter && nbr < 4)
	{
		f->old.re = f->new.re;
		f->old.im = f->new.im;
		f->new.im = -f->old.im * (5 * mult(f->old.re) - 10 *
				mult2(f->old.im, f->old.re) +
				mult2(mult(f->old.im), f->old.im)) + f->c.im;
		f->new.re = f->old.re * (mult2(mult(f->old.re), f->old.re) - 10 *
				mult2(f->old.im, f->old.re) + 5 *
				mult2(mult(f->old.im), f->old.im)) + f->c.re;
		nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	}
}

void	mand_tricorn(t_fractol *f, int *i)
{
	double	nbr;

	init_complex(f);
	nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	while ((*i)++ < f->maxiter && nbr < 4)
	{
		f->old.re = f->new.re;
		f->old.im = f->new.im;
		f->new.im = f->old.re * f->old.im * -2.0 + f->c.im;
		f->new.re = mult(f->old.re) - mult(f->old.im) + f->c.re;
		nbr = f->new.re * f->new.re + f->new.im * f->new.im;
	}
}
