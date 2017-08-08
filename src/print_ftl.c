/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ftl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 13:30:37 by agaspard          #+#    #+#             */
/*   Updated: 2017/08/08 14:56:02 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iter_ftl(t_env *e)
{
	e->i = 0;
	while (((e->z_r * e->z_r) + (e->z_i * e->z_i)) < 4 && e->i < e->imax)
	{
		e->tmp = e->z_r;
		e->z_r = (e->z_r * e->z_r) - (e->z_i * e->z_i) + e->c_r;
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		(e->i)++;
	}
	if (e->i == e->imax)
		mlx_pixel_put_to_img(e, e->r, e->g, e->b);
}

void		mandelbrot(t_env *e)
{
//	e->bpp = 1;
//	e->szl = 1;
	e->r = 255;
	e->g = 255;
	e->b = 255;

	e->y = 0;
	while (e->y < 1000)
	{
		e->x = 0;
		while (e->x < 1000)
		{
			e->c_r = e->x / (1000 / (e->xf - e->xi)) + e->xi;
			e->c_i = e->y / (1000 / (e->yf - e->yi)) + e->yi;
			e->z_r = 0;
			e->z_i = 0;
			iter_ftl(e);
			(e->x)++;
		}
		(e->y)++;
	}
}
