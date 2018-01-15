/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:40:58 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 14:40:04 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_pixel(t_env *e)
{
	int	i;

	i = (e->y * e->zline) + (e->x * (e->bpp / 8));
	e->pxl_img[i] = (char)(e->color >> 16);
	e->pxl_img[i + 1] = (char)(e->color >> 8);
	e->pxl_img[i + 2] = (char)(e->color);
}

void	init_window(t_env *e, char **av)
{
	if (ft_strcmp("mandelbrot", av[1]) == 0)
	{
		e->win_width = 1200;
		e->win_high = 1067;
	}
	else
	{
		e->win_width = 1000;
		e->win_high = 1000;
	}
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_high, "fractol");
}

void	select_fractal(char **av, t_env *e)
{
	init_window(e, av);
	if (ft_strcmp("julia", av[1]) == 0)
		ft_julia(e);
	else if (ft_strcmp("mandelbrot", av[1]) == 0)
		ft_mandelbrot(e);
	else if (ft_strcmp("burnship", av[1]) == 0)
		ft_burnship(e);
}
