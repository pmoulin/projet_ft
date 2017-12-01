/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:20:34 by phmoulin          #+#    #+#             */
/*   Updated: 2017/04/13 19:56:02 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
# define DB(x) ft_putendl(x)
# define W_NAME "FDF"
# define X_SIZE 1000
# define Y_SIZE 1000
# define ABS(x) ((x) >= 0 ? (x) : -(x))

typedef struct		s_img
{
	int				bts;
	int				size_l;
	char			*bts_img;
	void			*ptr_img;
	int				bpp;
	int				x;
	int				y;
	int				endian;
}					t_img;

typedef struct		s_parseur
{
	int				size;
	int				**parse;
}					t_parseur;

typedef struct		s_env
{
	int				x;
	int				y;
	int				save;
	void			*win;
	void			*mlx;
}					t_env;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			p;
	double			radiant;
	double			zo;
	int				size;
}					t_point;

typedef struct		s_global
{
	t_point			***pos;
	t_point			***pos2;
	int				key;
	t_parseur		*parseur;
	t_img			*img;
	t_env			*env;
	t_point			point;
}					t_global;

void				ft_check_file(char *path);
void				ft_check_parseur(t_global *global, char *path);
void				ft_gen_img(t_global *global, int key);
void				ft_basiquex(t_point *b, t_point *a, t_global *global);
void				ft_basiquey(t_point *b, t_point *a, t_global *global);
void				ft_error(int error);
void				ft_gen_map(t_global *global, int key);
void				ft_malloc_pos(t_global *global);
void				ft_matrice(t_global *global, int choix, int x, int y);
void				ft_gen_win(t_global *global);
void				ft_pix_put(t_global *global, int x, int y, int color);
void				ft_put_img(t_global *global, int x, int y, int color);
void				ft_draw_line(t_global *global, t_point a,
						t_point b, int color);
void				ft_change_pos(t_global *global, int key);
void				ft_zoom(t_global *global, int keycode);
void				ft_modif_z(t_global *global, int keycode);
void				ft_trace(t_point *b, t_point *a, t_global *global,
						int key);
int					ft_alloc_y(t_global *global, char *line, char *path);
int					modif_colors(t_global *global, int y);
int					ft_my_key_func(int keycode, void *param, t_global *global);
int					ft_read_file(char *path, t_global *global);
void				ft_split(char *line, t_global *global, int y, int i);
#endif
