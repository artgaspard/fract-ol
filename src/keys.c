/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:55:22 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 15:01:59 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		mouse_hook(int keycode, int x, int y, t_env *e)
{
	if (keycode == KEY_SCROLL_UP)
		zoom_in(e, x, y);
	if (keycode == KEY_SCROLL_DOWN)
		zoom_out(e, x, y);
	redraw(e);
	return (0);
}

int		mouse_moove(int x, int y, t_env *e)
{
	e->cr = ((float)(x - 150) / 800);
	e->ci = ((float)(y - 150) / 800);
	e->moove = 1;
	redraw(e);
	return (0);
}

int		gere_key(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
