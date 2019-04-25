/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:19:41 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 20:22:25 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	color(t_fractol *f, int iter)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	if (iter == f->maxiter)
		return (f->max_color);
	r = ((iter * 5)) * f->color + f->p.red;
	g = (255 - (iter * 10)) * f->color + f->p.green;
	b = (255 - (iter * 2)) * f->color * (iter < f->maxiter) + f->p.blue;
	return (set_color(r, g, b));
}

unsigned int	set_color(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r << 16) | (g << 8) | b);
}

void			psycho(t_fractol *f)
{
	f->max_color += 10000;
	if (f->max_color >= 0xffffff)
		f->max_color = 0x000000;
	f->color += 1;
}

void			menu_display(t_window *w, unsigned c)
{
	short	x;

	x = 0;
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 15, c,
			"Translate: [<-] [->] [^] [v]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 45, c, "Zoom In/Out:[+]/[-]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 75, c,
			"Iteration +/-: [Q] / [E]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 105, c,
			"Reset : [Space]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 135, c,
			"Psycho on: [P]  / off: [N]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 165, c,
			"Hide menu: [D]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 195, c,
			"Exit : [ESCAPE]");
}

void			menu(t_fractol *f)
{
	t_point		i;
	t_point		max;
	int			border;

	max.y = WIN_HEIGHT;
	max.x = f->menu_width;
	i.y = -1;
	border = 4;
	while (++i.y < max.y)
	{
		i.x = -1;
		while (++i.x < max.x)
		{
			if (i.x > border && i.x < max.x - border && i.y > border && i.y
					< max.y - border)
				mlx_pixel_put(f->w.mlx_ptr, f->w.win_ptr, i.x, i.y, 0xC0C0C0);
			else
				mlx_pixel_put(f->w.mlx_ptr, f->w.win_ptr, i.x, i.y, 0xC0C0C0);
		}
	}
	menu_display(&(f->w), 0x000000);
}
