/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:43:34 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 14:39:30 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		zoom_in(t_env *e, int x, int y)
{
	double	tmp;

	tmp = e->zoom;
	e->zoom *= 1.1;
	e->x1 += (((double)x / tmp) - (x / e->zoom));
	e->y1 += (((double)y / tmp) - (y / e->zoom));
	e->itmax *= 1.005;
}

void		zoom_out(t_env *e, int x, int y)
{
	double	tmp;

	tmp = e->zoom;
	e->zoom /= 1.1;
	e->x1 += (((double)x / tmp) - (x / e->zoom));
	e->y1 += (((double)y / tmp) - (y / e->zoom));
	e->itmax /= 1.005;
}
