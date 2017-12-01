/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:44:12 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 16:21:07 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# define DB(x) ft_putendl(x)
# define W_NAME "FRACTOL"
# define Y_SIZE 650
# define X_SIZE 800
# define ABS(x) ((x) > 0 ? (x) : -(x))

typedef struct		s_img
{
	char			*bts_img;
	void			*ptr_img;
	int				bts;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef struct		s_point
{
	double			centerx;
	double			centery;
	int				oldx;
	int				oldy;
	int				posy;
	int				posx;
	double			zoomx;
	double			zoomy;
	double			jrc;
	double			jic;
	double			x;
	double			y;
	double			ic;
	double			rc;
	double			rz;
	double			iz;
	double			x_max;
	double			x_min;
	double			y_min;
	double			y_max;
	double			zoom;
	double			a;
}					t_point;

typedef struct		s_env
{
	int				frac;
	double			range;
	int				param;
	int				m_x;
	int				m_y;
	void			*win;
	void			*mlx;
	double			x;
	double			y;
	t_img			*img;
	t_point			*point;
	int				it_m;
	int				key;
	int				on;
	void			*win2;
}					t_env;

void				error(int error);
void				init_struct(t_env *env);
void				change_fractal(t_env *env, int keycode);
void				reset(t_env *env);
void				help_win(t_env *env);
void				help(void);
void				zoom(t_env *env, int key);
void				fractal(t_env *env, char *param);
void				modif_size(t_env *env);
void				zoom_param(t_env *env, int key, int x, int y);
void				init_param(t_env *env);
void				gen_fractal(t_env *env);

void				burn_ship(t_env *env, int y, int x);
void				julia(t_env *env, int y, int x);
void				mandel(t_env *env, int y, int x);

void				modif_pos(t_env *env, int key);
void				create_win(t_env *env);
void				gen_fractal(t_env *env);
void				edit_color(t_env *env, int x, int y, int color);
void				test(t_env *env, int y, int x);
int					mouse_code(int x, int y, t_env *env);
int					my_key_func(int keycode, t_env *env);
int					my_key_func2(int keycode, t_env *env);
int					mouse_func(int keycode, int x, int y, t_env *env);
#endif
