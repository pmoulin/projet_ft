/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:30:44 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 15:08:47 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		calc_pos_select(int *y, char *path)
{
	if (ft_strcmp(path, "images/knif_select.xpm") == 0)
		*y = 1040;
	else if (ft_strcmp(path, "images/snipe_select.xpm") == 0)
		*y = 1080;
	else if (ft_strcmp(path, "images/aka_select.xpm") == 0)
		*y = 1000;
}

static void		arme_select(t_env *env, char *path)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	if ((env->img_ico.ptr_img = mlx_xpm_file_to_image(env->mlx, path,
			&x, &y)) == NULL)
		ft_error(4);
	env->img_ico.bts_img = mlx_get_data_addr(env->img_ico.ptr_img,
			&env->img_ico.bpp, &env->img_ico.size_l, &env->img_ico.endian);
	y = 0;
	x = 0;
	calc_pos_select(&y, path);
	mlx_put_image_to_window(env->mlx, env->win, env->img_ico.ptr_img, 500, y);
	ft_bzero(env->img_ico.bts_img, ft_strlen(env->img_ico.bts_img));
}

static void		calc_pos(int *y, char *path1)
{
	if (ft_strcmp(path1, "images/knif_no_select.xpm") == 0)
		*y = 1040;
	else if (ft_strcmp(path1, "images/snipe_no_select.xpm") == 0)
		*y = 1080;
	else if (ft_strcmp(path1, "images/aka_no_select.xpm") == 0)
		*y = 1000;
}

static void		arme_reseve(t_env *env, char *path1, char *path2)
{
	int		x;
	int		y;

	if ((env->img_ico.ptr_img = mlx_xpm_file_to_image(env->mlx, path1,
			&x, &y)) == NULL)
		ft_error(4);
	env->img_ico.bts_img = mlx_get_data_addr(env->img_ico.ptr_img,
			&env->img_ico.bpp, &env->img_ico.size_l, &env->img_ico.endian);
	y = 0;
	x = 0;
	calc_pos(&y, path1);
	mlx_put_image_to_window(env->mlx, env->win, env->img_ico.ptr_img, 500, y);
	ft_bzero(env->img_ico.bts_img, ft_strlen(env->img_ico.bts_img));
	y = 0;
	x = 0;
	if ((env->img_ico.ptr_img = mlx_xpm_file_to_image(env->mlx, path2, &x,
			&y)) == NULL)
		ft_error(4);
	env->img_ico.bts_img = mlx_get_data_addr(env->img_ico.ptr_img,
			&env->img_ico.bpp, &env->img_ico.size_l, &env->img_ico.endian);
	calc_pos(&y, path2);
	mlx_put_image_to_window(env->mlx, env->win, env->img_ico.ptr_img, 500, y);
	ft_bzero(env->img_ico.bts_img, ft_strlen(env->img_ico.bts_img));
}

void			weapon_select(t_env *env)
{
	int		x;

	x = env->weapon.choice_w;
	if (x == 0)
	{
		arme_select(env, "images/aka_select.xpm");
		arme_reseve(env, "images/knif_no_select.xpm",
				"images/snipe_no_select.xpm");
	}
	else if (x == 1)
	{
		arme_select(env, "images/knif_select.xpm");
		arme_reseve(env, "images/aka_no_select.xpm",
				"images/snipe_no_select.xpm");
	}
	else if (x == 2)
	{
		arme_select(env, "images/snipe_select.xpm");
		arme_reseve(env, "images/aka_no_select.xpm",
				"images/knif_no_select.xpm");
	}
}
