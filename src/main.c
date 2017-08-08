/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:43 by agaspard          #+#    #+#             */
/*   Updated: 2017/08/08 14:56:06 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			error_params(char *str)
{
	ft_putstr("Usage : ");
	ft_putstr(str);
	ft_putstr(" [julia] or [mandelbrot]\n");
	return (0);
}

int			selec_fra(char *str)
{
	if (ft_strcmp(str, "julia") == 0)
		return (1);
	else if (ft_strcmp(str, "mandelbrot") == 0)
		return (2);
	return (0);
}

int			ft_loop(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	create_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;
	int		fra;

	if (!av)
		return (error_params("./fractol"));
	if (ac != 2 || !(fra = selec_fra(av[1])) || \
			!(e = (t_env*)malloc(sizeof(t_env))))
		return (error_params(av[0]));
	init_mlx(fra, e);
	init_mandelbrot(e);
	mandelbrot(e);
//	mlx_pixel_put_to_img(e, e->r, e->g, e->b);
//	create_img(e);
	mlx_hook(e->win, 2, 3, gere_key, e);
	mlx_loop_hook(e->mlx, ft_loop, e);
	mlx_loop(e->mlx);
	return (0);
}
