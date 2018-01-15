/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:03:35 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 14:38:42 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		error_params(void)
{
	ft_putstr("Usage : ./fractol [julia] or [mandelbrot] or [burnship]\n");
}

int			check_params(int ac, char **av)
{
	if (ac != 2)
	{
		error_params();
		return (1);
	}
	if (ft_strcmp("julia", av[1]) != 0 && \
			ft_strcmp("mandelbrot", av[1]) != 0 && \
			ft_strcmp("burnship", av[1]) != 0)
	{
		error_params();
		return (1);
	}
	return (0);
}

void		redraw(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_width, e->win_high);
	e->pxl_img = mlx_get_data_addr(e->img, &e->bpp, &e->zline, &e->endian);
	if (e->number_set == 0)
		draw_julia(e);
	else if (e->number_set == 1)
		draw_mandelbrot(e);
	else if (e->number_set == 2)
		draw_burnship(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (check_params(ac, av) == 1)
		return (0);
	if ((e = (t_env*)malloc(sizeof(t_env))) == 0)
	{
		ft_putstr("error first malloc");
		return (0);
	}
	select_fractal(av, e);
	mlx_hook(e->win, 3, 0, gere_key, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, 0, mouse_moove, e);
	mlx_loop(e->mlx);
	return (0);
}
