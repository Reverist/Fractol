/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:24:56 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 21:27:00 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mult(double a)
{
	return (a * a);
}

double	mult2(double a, double b)
{
	return (a * b);
}

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void	drawline(t_fractol *p, t_matrix p0, t_matrix p1)
{
	t_matrix	dif;
	t_matrix	i;
	int			pixel;
	double		tmp;

	dif.x = fabs(p1.x - p0.x);
	dif.y = fabs(p1.y - p0.y);
	tmp = (dif.x > dif.y) ? dif.x : dif.y;
	pixel = (!round(tmp)) ? 1 : round(tmp);
	i.x = dif.x / tmp * (p0.x < p1.x ? 1 : -1);
	i.y = dif.y / tmp * (p0.y < p1.y ? 1 : -1);
	while (pixel--)
	{
		if ((p0.x > WIN_WIDTH && p0.x < 0) && (p0.y > WIN_HEIGHT && p0.y < 0))
			pixel = 0;
		sierp_pixel(p, p0, 0xFFFFFF);
		p0.x += i.x;
		p0.y += i.y;
	}
}

void	sierp_pixel(t_fractol *p, t_matrix a, int color)
{
	int x;
	int y;

	x = round(a.x);
	y = round(a.y);
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		*(int *)&p->w.ptr[(x * p->w.bits_per_pixel) +
			(y * p->w.size_line)] = color;
}
