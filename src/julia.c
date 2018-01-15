/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:13:40 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 14:42:24 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_env		*ft_init_julia(t_env *e)
{
	e->x1 = -1;
	e->x2 = 1;
	e->y1 = -1;
	e->y2 = 1;
	e->zoom = 500;
	e->itmax = 100;
	e->imgx = (e->x2 - e->x1) * e->zoom;
	e->imgy = (e->y2 - e->y1) * e->zoom;
	return (e);
}

t_env		*ft_init_draw_julia(t_env *e, int x, int y)
{
	if (e->moove == 0)
	{
		e->cr = 0.284;
		e->ci = 0.01;
	}
	e->zr = x / e->zoom + e->x1;
	e->zi = y / e->zoom + e->y1;
	e->i = 0;
	return (e);
}

void		draw_julia(t_env *e)
{
	float	tmp;

	e->y = -1;
	while (++e->y < e->imgy)
	{
		e->x = -1;
		while (++e->x < e->imgx)
		{
			e = ft_init_draw_julia(e, e->x, e->y);
			while ((e->zr * e->zr + e->zi * e->zi) < 4 && e->i <= e->itmax)
			{
				tmp = e->zr;
				e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
				e->zi = 2 * e->zi * tmp + e->ci;
				e->i++;
			}
			e->color = set_color(e);
			if ((e->y < e->imgy) && (e->x < e->imgx))
				put_pixel(e);
		}
	}
}

void		ft_julia(t_env *e)
{
	e = ft_init_julia(e);
	e->number_set = 0;
	e->img = mlx_new_image(e->mlx, e->imgx, e->imgy);
	e->pxl_img = mlx_get_data_addr(e->img, &e->bpp, &e->zline, &e->endian);
	draw_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
