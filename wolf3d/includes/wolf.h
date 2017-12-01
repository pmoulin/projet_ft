/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:19:05 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 23:23:22 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include "../minilibx_macos/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# define W_N "WOLF3D"
# define X_S 1000
# define Y_S 1000
# define Y_W 1140
# define X_W 1000
# define ABS(x) ((x) > 0 ? (x) : -(x))
# define DB(x) ft_putendl(x)

typedef struct		s_img
{
	char			*bts_img;
	void			*ptr_img;
	int				endian;
	int				size_l;
	int				bpp;
	int				bts;
}					t_img;

typedef struct		s_weapon
{
	char			*bts_img;
	void			*ptr_img;
	int				endian;
	int				size_l;
	int				bpp;
	int				bts;
	int				choice_w;
	char			*path_w[3];
	int				x;
	int				y;
}					t_weapon;

typedef struct		s_player
{
	double			x;
	double			y;
	double			z;
	double			d_vision;
}					t_player;

typedef struct		s_cam
{
	double			pcam_x;
	double			pcam_y;
	double			dirx;
	double			diry;
	double			plx;
	double			ply;
	double			r_px;
	double			r_py;
	double			dr_rx;
	double			dr_ry;
	double			camx;
	int				mapx;
	int				mapy;
	double			distx;
	double			disty;
	double			size_rx;
	double			size_ry;
	double			side;
	double			v_move;
	double			movey;
	double			movex;
}					t_cam;

typedef struct		s_map
{
	char			**map;
	int				line;
	int				nb_case;
	double			**c_map;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				min_map;
	int				x;
	t_weapon		weapon;
	t_img			img_m;
	t_img			img_me;
	t_cam			cam;
	t_img			img_ico;
	t_img			img;
	t_map			map;
}					t_env;

int					my_key_hook(int key, t_env *env);
int					cordo_start(t_env *env, int x, int y);
int					exit_red(int key, t_env *env);
int					detect_mur(t_env *env, int *stepx, int *stepy);

void				check_map(t_env *env);
void				weapon_select(t_env *env);
void				weapon(t_env *env, int i);
void				edit_color_me(t_env *env, int x, int y, int color);
void				edit_color_ico(t_env *env, int x, int y, int color);
void				ft_error(int error);
void				gen_menu_down(t_env *env);
void				gen_mini_map(t_env *env);
void				edit_color_mini_map(t_env *env, int x, int y, int color);
void				init_struct(t_env *env, int choice);
void				move_pos_cam(t_env *env, int key);
void				move_angle_cam(t_env *env, int key);
void				aff_mur(t_env *env, int x, double wall_dist);
void				init_param_cam(t_env *env, int x);
void				gen_map(t_env *env);
void				create_win_img(t_env *env);
void				parseur(t_env *env, char *path);
void				read_files(t_env *env, int fd);
void				edit_color(t_env *env, int x, int y, int color);
#endif
