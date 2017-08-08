/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:44:22 by agaspard          #+#    #+#             */
/*   Updated: 2017/08/08 14:55:44 by agaspard         ###   ########.fr       */
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

typedef	struct	s_siz
{
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
}				t_siz;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			szl;
	int			endian;
	int			fra;
	double		xi;
	double		yi;
	double		xf;
	double		yf;
	int			imax;
	int			x;
	int			y;
	int			tmp;
	int			c_r;
	int			c_i;
	int			z_r;
	int			z_i;
	int			i;
	int			r;
	int			g;
	int			b;



	int			xmax;
	int			ymax;
	int			zmax;
	int			width;
	int			height;
	int			x_mid;
	int			y_mid;
	int			mv_lr;
	int			mv_ud;
	double		z_size;
	float		dx;
	float		dy;
	float		xinc;
	float		yinc;
	float		cumul;
	t_siz		*w_size;
}				t_env;

int				error_params(char *str);
int				selec_fra(char *str);
void			init_fra(int fra, t_env *e);
void			init_mlx(int fra, t_env *e);
void			create_img(t_env *e);
void			mlx_pixel_put_to_img(t_env *e, char r, char g, char b);
void			mandelbrot(t_env *e);

void			init_julia(t_env *e);
void			init_mandelbrot(t_env *e);

int				error_fd(char **av, t_env *e, int error);
void			height_color(t_env *e);
int				gere_key(int keycode);
int				gere_key2(int keycode, t_env *e);
int				loop_event(t_env *e);
void			print_line(t_env *e);
void			iso(t_env *e, int count);
void			get_coor(t_env *e);
int				get_max(char *av, t_env *e);
void			resize(t_siz *s, t_env *e);
void			init(t_siz *s, t_env *e);
t_siz			*win_size(t_env *e);

#endif
