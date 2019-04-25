/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:27:14 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 20:32:47 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *f, int k)
{
	if (k == KEY_PAD_ADD)
		f->zoom *= 1.25;
	else if (k == KEY_PAD_SUB)
		f->zoom *= 0.9;
	else if (k == KEY_SPACE)
	{
		f->zoom = 0.5;
		f->move_x = 0;
		f->move_y = 0;
	}
}

void	iter(t_fractol *f, int k)
{
	if (k == KEY_Q)
	{
		f->maxiter += 2;
		f->depth += 1;
	}
	if (k == KEY_E)
	{
		f->maxiter -= 2;
		f->depth -= 1;
	}
}

void	shape(t_fractol *f, int k)
{
	if (k == KEY_Z)
		f->c.im += 0.0002;
	if (k == KEY_X)
		f->c.im -= 0.0002;
	if (k == KEY_C)
		f->c.re += 0.0002;
	if (k == KEY_V)
		f->c.re -= 0.0002;
}

int		user_hook(int k, t_fractol *f)
{
	if (k == 53)
		exit(0);
	if (k == 53)
		mlx_destroy_window(f->w.mlx_ptr, f->w.win_ptr);
	if (k == KEY_P)
		f->psyduck = 1;
	if (k == KEY_N)
		f->psyduck = 0;
	else
	{
		zoom(f, k);
		shape(f, k);
		iter(f, k);
		translate(f, k);
		menu_hook(f, k);
		mlx_clear_window(f->w.mlx_ptr, f->w.win_ptr);
		mlx(f);
	}
	return (0);
}

void	draw_square(t_fractol *f, t_carp *c)
{
	t_matrix i;

	i.y = c->p1.y;
	while (i.y++ < c->p2.y)
	{
		i.x = c->p1.x;
		while (i.x++ < c->p2.x)
			sierp_pixel(f, i, 0xFFFFFF);
	}
}
