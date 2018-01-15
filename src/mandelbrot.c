/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:32:00 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 14:41:36 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_env		*ft_init_mandelbrot(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 445;
	e->itmax = 100;
	e->imgx = (e->x2 - e->x1) * e->zoom;
	e->imgy = (e->y2 - e->y1) * e->zoom;
	return (e);
}

t_env		*ft_init_draw_mandelbrot(t_env *e, int x, int y)
{
	e->cr = x / e->zoom + e->x1;
	e->ci = y / e->zoom + e->y1;
	e->zr = 0;
	e->zi = 0;
	e->i = 0;
	return (e);
}

void		draw_mandelbrot(t_env *e)
{
	double	tmp;

	e->y = -1;
	while (++e->y < e->imgy)
	{
		e->x = -1;
		while (++e->x < e->imgx)
		{
			e = ft_init_draw_mandelbrot(e, e->x, e->y);
			while ((e->zr * e->zr + e->zi * e->zi) < 4 && e->i < e->itmax)
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

void		ft_mandelbrot(t_env *e)
{
	e = ft_init_mandelbrot(e);
	e->number_set = 1;
	e->img = mlx_new_image(e->mlx, e->imgx, e->imgy);
	e->pxl_img = mlx_get_data_addr(e->img, &e->bpp, &e->zline, &e->endian);
	draw_mandelbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
