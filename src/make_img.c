/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:06:43 by agaspard          #+#    #+#             */
/*   Updated: 2017/08/08 14:56:09 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(int fra, t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		ft_putstr("mlx initiation failed\n");
	e->fra = fra;
	e->win = mlx_new_window(e->mlx, 1000, 1000, "fract'ol");
	create_img(e);
}

void	create_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->szl), &(e->endian));
}

void	mlx_pixel_put_to_img(t_env *e, char r, char g, char b)
{
	unsigned int i;
	unsigned int x;
	unsigned int y;

//	printf("bpp %d szl %d\n", e->bpp, e->szl);
	// initialiser bpp, szl !
	if (e->x < 1000 && e->y < 1000)
	{
		i = 0;
		x = e->x * e->bpp / 8;
		y = e->y * e->szl;
//		printf("x = %d, y = %d, i = %d\n", x, y, i);
		e->data[x + i++ + y] = b;
		e->data[x + i++ + y] = g;
		e->data[x + i + y] = r;
//	printf("x = %d, y = %d, i = %d\n", x, y, i);
	}
}
/*
int		ftl(int ac, char **av)
{
	t_env	*e;

	if ((e = (t_env*)malloc(sizeof(t_env))) == 0)
		return (0);
	if (ac == 2 && ((ft_strcmp(av[1], "julia") == 0) || (ft_strcmp(av[1], "mandelbrot") == 0)))
	{
		init_mlx(e);
		mandel(e);
		get_coor(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_hook(e->win, 2, 3, gere_key, e);
		mlx_loop_hook(e->mlx, &loop_event, e);
		mlx_loop(e->mlx);
	}
	else
		return (error_param(av));
	return (0);
}*/
