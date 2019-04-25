/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:05:13 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/25 16:07:33 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	carpet(t_fractol *f)
{
	t_carp	c;

	if (f->zoom < 1)
		f->zoom = 1;
	c = (t_carp) {{(0 + f->move_x) * f->zoom, (0 + f->move_y) * f->zoom},
		{((WIN_WIDTH - 1) + f->move_x) * f->zoom,
		((WIN_HEIGHT - 1) + f->move_y) * f->zoom}};
	draw_carpet(f, &c, 1);
}

void	draw_carpet(t_fractol *f, t_carp *c, int n)
{
	t_carp	tmp;

	tmp = carp_point(c, 1);
	draw_square(f, &tmp);
	if (n < f->depth)
	{
		tmp = carp_point(c, 2);
		draw_carpet(f, &tmp, n + 1);
		tmp = carp_point(c, 3);
		draw_carpet(f, &tmp, n + 1);
		tmp = carp_point(c, 4);
		draw_carpet(f, &tmp, n + 1);
		tmp = poits_carp(c, 5);
		draw_carpet(f, &tmp, n + 1);
		tmp = poits_carp(c, 6);
		draw_carpet(f, &tmp, n + 1);
		tmp = poits_carp(c, 7);
		draw_carpet(f, &tmp, n + 1);
		tmp = poits_carp(c, 8);
		draw_carpet(f, &tmp, n + 1);
		tmp = poits_carp(c, 9);
		draw_carpet(f, &tmp, n + 1);
	}
}

t_carp	carp_point(t_carp *c, int flag)
{
	t_carp new;

	if (flag == 1)
		new = (t_carp) {{((2 * c->p1.x + c->p2.x) / 3.0),
			((2 * c->p1.y + c->p2.y) / 3.0)},
		{(((c->p1.x + 2 * c->p2.x) / 3.0) - 1),
			(((c->p1.y + 2 * c->p2.y) / 3.0) - 1)}};
	if (flag == 2)
		new = (t_carp) {{c->p1.x, c->p1.y}, {((2 * c->p1.x + c->p2.x) / 3.0),
			((2 * c->p1.y + c->p2.y) / 3.0)}};
	if (flag == 3)
		new = (t_carp) {{((2 * c->p1.x + c->p2.x) / 3.0), c->p1.y},
			{((c->p1.x + 2 * c->p2.x) / 3.0), ((2 * c->p1.y + c->p2.y) / 3.0)}};
	if (flag == 4)
		new = (t_carp) {{((c->p1.x + 2 * c->p2.x) / 3.0), c->p1.y},
			{c->p2.x, ((2 * c->p1.y + c->p2.y) / 3.0)}};
	return (new);
}

t_carp	poits_carp(t_carp *c, int flag)
{
	t_carp	new;

	if (flag == 5)
		new = (t_carp) {{c->p1.x, ((2 * c->p1.y + c->p2.y) / 3.0)},
			{((2 * c->p1.x + c->p2.x) / 3.0), ((c->p1.y + 2 * c->p2.y) / 3.0)}};
	if (flag == 6)
		new = (t_carp) {{((c->p1.x + 2 * c->p2.x) / 3.0),
			((2 * c->p1.y + c->p2.y) / 3.0)},
			{c->p2.x, ((c->p1.y + 2 * c->p2.y) / 3.0)}};
	if (flag == 7)
		new = (t_carp) {{c->p1.x, ((c->p1.y + 2 * c->p2.y) / 3.0)},
			{((2 * c->p1.x + c->p2.x) / 3.0), c->p2.y}};
	if (flag == 8)
		new = (t_carp) {{((2 * c->p1.x + c->p2.x) / 3.0),
			((c->p1.y + 2 * c->p2.y) / 3.0)}, {((c->p1.x + 2 * c->p2.x) / 3.0),
			c->p2.y}};
	if (flag == 9)
		new = (t_carp) {{((c->p1.x + 2 * c->p2.x) / 3.0),
			((c->p1.y + 2 * c->p2.y) / 3.0)}, {c->p2.x, c->p2.y}};
	return (new);
}

void	init_complex(t_fractol *f)
{
	f->new.re = 0;
	f->new.im = 0;
	f->old.re = 0;
	f->old.im = 0;
}
