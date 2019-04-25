/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:18:42 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/24 21:23:56 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx(t_fractol *f)
{
	new_image(f);
	if (f->psyduck)
		psycho(f);
	if (!ft_strcmp(f->fractal, "Julia"))
		fractol(f);
	else if (!ft_strcmp(f->fractal, "Sierpinski_triangle"))
		drawsierpinski(f);
	else if (!ft_strcmp(f->fractal, "Sierpinski_carpet"))
		carpet(f);
	else
		frac_iter(f);
	menu(f);
	mlx_put_image_to_window(f->w.mlx_ptr, f->w.win_ptr,
			f->w.img, f->menu_width, 0);
	mlx_hook(f->w.win_ptr, KEYPRESS, KEYPRESSMASK, user_hook, f);
	mlx_hook(f->w.win_ptr, 4, 0, wheel_hook, f);
	mlx_hook(f->w.win_ptr, 6, 0, mouse_move, f);
	mlx_loop(f->w.mlx_ptr);
}

void	new_image(t_fractol *f)
{
	f->w.img = mlx_new_image(f->w.mlx_ptr, 1280, 720);
	f->w.ptr = mlx_get_data_addr(f->w.img,
			&f->w.bits_per_pixel, &f->w.size_line, &f->w.endian);
	f->w.bits_per_pixel /= 8;
}

void	get_type(t_fractol *f, char *title)
{
	if (!ft_strcmp(title, "Julia") || !ft_strcmp(title, "Mandelbrot") ||
			!ft_strcmp(title, "Cubic_ship") ||
			!ft_strcmp(title, "Tricorn") ||
			!ft_strcmp(title, "V_mandelbrot") ||
			!ft_strcmp(title, "Celtic_heart") ||
			!ft_strcmp(title, "Sierpinski_triangle") ||
			!ft_strcmp(title, "Sierpinski_carpet"))
	{
		f->fractal = ft_strdup(title);
		return ;
	}
	error("Please insert the valid name of the fractal");
}

void	init(t_fractol *f)
{
	f->zoom = 0.5;
	f->depth = 7;
	f->p = (t_rgb) { .red = 0, .green = 0, .blue = 0 };
	f->color = 1;
	f->max_color = 0xCD5C5C;
	f->psyduck = 0;
	f->menu = 1;
	if (!ft_strcmp(f->fractal, "Mandelbrot"))
	{
		f->move_x = -0.5;
		f->move_y = 0;
	}
	if (!ft_strcmp(f->fractal, "Julia"))
	{
		f->c.re = -0.7;
		f->c.im = 0.27015;
		f->move_x = 0;
		f->move_y = 0;
	}
	if (!ft_strcmp(f->fractal, "Sierpinski_triangle") ||
			!ft_strcmp(f->fractal, "Sierpinski_carpet"))
		f->zoom = 1;
}

int		main(int ac, char **av)
{
	t_fractol f;

	if (ac != 2)
	{
		error("Usage: ./fractol\t[parameter]\n\t\t\t Julia\
		\n\t\t\t Mandelbrot\n\t\t\t Cubic_ship\n\t\t\t V_mandelbrot\
	\n\t\t\t Celtic_heart\n\t\t\t Tricorn\n\t\t\t Sierpinski_triangle\
	\n\t\t\t Sierpinski_carpet");
	}
	get_type(&f, av[1]);
	init(&f);
	f.maxiter = 20;
	f.w.mlx_ptr = mlx_init();
	f.w.win_ptr = mlx_new_window(f.w.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	mlx(&f);
}
