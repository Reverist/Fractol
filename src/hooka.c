/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:15:01 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 21:18:18 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_fractol *f)
{
	if ((x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT))
	{
		f->c.re += ((double)x - f->mouse.click_x) / (WIN_WIDTH * 2);
		f->c.im += ((double)y - f->mouse.click_y) / (WIN_HEIGHT * 2);
		f->mouse.click_x = x;
		f->mouse.click_y = y;
		mlx(f);
	}
	return (0);
}

int		wheel_hook(int b, int x, int y, t_fractol *f)
{
	if ((b == 5 || b == 4) && (x > 0 && x < WIN_WIDTH &&
				y > 0 && y < WIN_HEIGHT))
	{
		mouse_zoom(b, f, x, y);
		mlx(f);
	}
	return (0);
}

void	translate(t_fractol *f, int k)
{
	if (k == KEY_UP)
		f->move_y += 0.5;
	if (k == KEY_DOWN)
		f->move_y -= 0.5;
	if (k == KEY_LEFT)
		f->move_x += 0.5;
	if (k == KEY_RIGHT)
		f->move_x -= 0.5;
}

void	mouse_zoom(int k, t_fractol *f, int x, int y)
{
	y -= WIN_HEIGHT / 2;
	x -= WIN_WIDTH / 2;
	if (k == 4)
	{
		f->zoom *= 1.1;
		f->move_x = x * f->zoom / WIN_WIDTH;
		f->move_y = y * f->zoom / WIN_HEIGHT;
	}
	if (k == 5)
	{
		f->zoom *= 0.9;
		f->move_x = x * f->zoom / WIN_WIDTH;
		f->move_y = y * f->zoom / WIN_HEIGHT;
	}
}

void	menu_hook(t_fractol *f, int k)
{
	if (k == KEY_M)
		f->menu_width = 280;
	if (k == KEY_D)
		f->menu_width = 0;
}
