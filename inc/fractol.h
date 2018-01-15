/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:00:10 by agaspard          #+#    #+#             */
/*   Updated: 2017/12/03 15:02:10 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define KEY_ESC 53
# define KEY_SCROLL_UP 5
# define KEY_SCROLL_DOWN 4

typedef struct		s_env {
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl_img;
	int				bpp;
	int				zline;
	int				endian;
	int				win_high;
	int				win_width;
	int				imgx;
	int				imgy;
	int				x;
	int				y;
	int				color;
	int				c1;
	int				c2;
	int				c3;
	int				number_set;
	int				moove;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			i;
	long double		zoom;
	long double		itmax;
}					t_env;

void				redraw(t_env *e);
void				error_params(void);
int					check_params(int ac, char **av);
void				put_pixel(t_env *e);
void				init_window(t_env *e, char **av);
void				select_fractal(char **av, t_env *e);
void				zoom_in(t_env *e, int x, int y);
void				zoom_out(t_env *e, int x, int y);
int					gere_key(int keycode);
int					mouse_hook(int keycode, int x, int y, t_env *e);
int					mouse_moove(int x, int y, t_env *e);
t_env				*ft_init_julia(t_env *e);
t_env				*ft_init_draw_julia(t_env *e, int x, int y);
void				draw_julia(t_env *e);
void				ft_julia(t_env *e);
t_env				*ft_init_draw_mandelbrot(t_env *e, int x, int y);
t_env				*ft_init_mandelbrot(t_env *e);
void				draw_mandelbrot(t_env *e);
void				ft_mandelbrot(t_env *e);
t_env				*ft_init_burnship(t_env *e);
t_env				*ft_init_draw_burnship(t_env *e, int x, int y);
void				draw_burnship(t_env *e);
void				ft_burnship(t_env *e);
int					pixel_color(t_env *e);
int					set_color(t_env *e);
int					color_set_julia(t_env *e);
int					color_set_mandelbrot(t_env *e);
int					color_set_burnship(t_env *e);

#endif
