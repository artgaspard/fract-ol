/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:31:00 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 14:39:06 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			pixel_color(t_env *e)
{
	if (e->i < 33)
		return (e->c1 + (e->i * 10));
	if (e->i >= 33 && e->i < 66)
		return (e->c2 + (e->i * 10));
	if (e->i >= 660 && e->i < e->itmax)
		return (e->c3 + (e->i * 10));
	if (e->i >= e->itmax)
		return (0);
	return (16777215 + (e->i));
}

int			color_set_julia(t_env *e)
{
	e->c1 = 5000000;
	e->c2 = 6000000;
	e->c3 = 7000000;
	return (pixel_color(e));
}

int			color_set_mandelbrot(t_env *e)
{
	e->c1 = 30000000;
	e->c2 = 16744272;
	e->c3 = 80000000;
	return (pixel_color(e));
}

int			color_set_burnship(t_env *e)
{
	e->c1 = 16777250;
	e->c2 = 16777215;
	e->c3 = 16777215;
	return (pixel_color(e));
}

int			set_color(t_env *e)
{
	int		set;

	if (e->number_set == 0)
		set = color_set_julia(e);
	if (e->number_set == 1)
		set = color_set_mandelbrot(e);
	if (e->number_set == 2)
		set = color_set_burnship(e);
	return (set);
}
