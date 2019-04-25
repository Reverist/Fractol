/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:27:10 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 21:34:27 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drawsierpinski(t_fractol *f)
{
	t_tri t;
	t_tri tmp;

	if (f->zoom < 1)
		f->zoom = 1;
	t = (t_tri) { .p1.x = (10 + f->move_x) * f->zoom,
		.p1.y = (WIN_HEIGHT - 10 + f->move_y) * f->zoom,
		.p2.x = (WIN_WIDTH - 10 + f->move_x) * f->zoom,
		.p2.y = (WIN_HEIGHT - 10 + f->move_y) * f->zoom,
		.p3.x = (WIN_WIDTH / 2 + f->move_x) * f->zoom,
		.p3.y = (10 + f->move_y) * f->zoom};
	drawline(f, t.p1, t.p2);
	drawline(f, t.p1, t.p3);
	drawline(f, t.p2, t.p3);
	tmp = coord(&t, 1);
	subtri(f, &tmp, 1);
}

void	subtri(t_fractol *f, t_tri *t, int n)
{
	t_tri	tmp;

	drawline(f, t->p1, t->p2);
	drawline(f, t->p1, t->p3);
	drawline(f, t->p2, t->p3);
	if (n < f->depth)
	{
		tmp = coord(t, 2);
		subtri(f, &tmp, n + 1);
		tmp = coords(t, 3);
		subtri(f, &tmp, n + 1);
		tmp = coords(t, 4);
		subtri(f, &tmp, n + 1);
	}
}

t_tri	coord(t_tri *t, int flag)
{
	t_tri new;

	if (flag == 1)
	{
		new.p1.x = (t->p1.x + t->p2.x) / 2;
		new.p1.y = (t->p1.y + t->p2.y) / 2;
		new.p2.x = (t->p1.x + t->p3.x) / 2;
		new.p2.y = (t->p1.y + t->p3.y) / 2;
		new.p3.x = (t->p2.x + t->p3.x) / 2;
		new.p3.y = (t->p2.y + t->p3.y) / 2;
	}
	if (flag == 2)
	{
		new.p1.x = (t->p1.x + t->p2.x) / 2 + (t->p2.x - t->p3.x) / 2;
		new.p1.y = (t->p1.y + t->p2.y) / 2 + (t->p2.y - t->p3.y) / 2;
		new.p2.x = (t->p1.x + t->p2.x) / 2 + (t->p1.x - t->p3.x) / 2;
		new.p2.y = (t->p1.y + t->p2.y) / 2 + (t->p1.y - t->p3.y) / 2;
		new.p3.x = (t->p1.x + t->p2.x) / 2;
		new.p3.y = (t->p1.y + t->p2.y) / 2;
	}
	return (new);
}

t_tri	coords(t_tri *t, int flag)
{
	t_tri new;

	if (flag == 3)
	{
		new.p1.x = (t->p3.x + t->p2.x) / 2 + (t->p2.x - t->p1.x) / 2;
		new.p1.y = (t->p3.y + t->p2.y) / 2 + (t->p2.y - t->p1.y) / 2;
		new.p2.x = (t->p3.x + t->p2.x) / 2 + (t->p3.x - t->p1.x) / 2;
		new.p2.y = (t->p3.y + t->p2.y) / 2 + (t->p3.y - t->p1.y) / 2;
		new.p3.x = (t->p3.x + t->p2.x) / 2;
		new.p3.y = (t->p3.y + t->p2.y) / 2;
	}
	if (flag == 4)
	{
		new.p1.x = (t->p1.x + t->p3.x) / 2 + (t->p3.x - t->p2.x) / 2;
		new.p1.y = (t->p1.y + t->p3.y) / 2 + (t->p3.y - t->p2.y) / 2;
		new.p2.x = (t->p1.x + t->p3.x) / 2 + (t->p1.x - t->p2.x) / 2;
		new.p2.y = (t->p1.y + t->p3.y) / 2 + (t->p1.y - t->p2.y) / 2;
		new.p3.x = (t->p1.x + t->p3.x) / 2;
		new.p3.y = (t->p1.y + t->p3.y) / 2;
	}
	return (new);
}
