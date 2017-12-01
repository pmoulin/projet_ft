/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_mini_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:53:30 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 22:30:10 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		pos_cam(t_env *env, int x1, int y1)
{
	int		x;
	int		y;
	int		x2;
	int		y2;

	x2 = env->cam.pcam_x * x1;
	y2 = env->cam.pcam_y * y1;
	y = y2 - (y1 / 2);
	while (y < y2 + (y1 / 2))
	{
		x = x2 - (x1 / 2);
		while (x < x2 + (x1 / 2))
		{
			edit_color_mini_map(env, x, y, 0x00FE1B00);
			x++;
		}
		y++;
	}
}

static void		color_map(t_env *env, int y, int x, int c)
{
	int		y1;
	int		x1;
	int		v;
	int		i;

	y1 = Y_S / env->map.line;
	x1 = X_S / env->map.nb_case;
	i = y * y1;
	while (i < (y + 1) * y1)
	{
		v = x * x1;
		while (v < (x + 1) * x1)
		{
			if (c == 1)
				edit_color_mini_map(env, v, i, 0x00000000);
			else if (c == 0)
				edit_color_mini_map(env, v, i, 0x00FFFFFF);
			else if (c == 3)
				edit_color_mini_map(env, v, i, 0x000000FF);
			v++;
		}
		i++;
	}
}

void			gen_mini_map(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	env->map.nb_case = ft_strlen(env->map.map[0]);
	while (env->map.map[y])
	{
		x = 0;
		while (env->map.map[y][x])
		{
			if (env->map.map[y][x] == '1')
				color_map(env, y, x, 1);
			else if (env->map.map[y][x] == '0')
				color_map(env, y, x, 0);
			else if (env->map.map[y][x] == '3')
				color_map(env, y, x, 3);
			x++;
		}
		y++;
	}
	pos_cam(env, X_S / env->map.nb_case, Y_S / env->map.line);
	mlx_clear_window(env->mlx, env->win);
	gen_menu_down(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img_m.ptr_img, 0, 0);
}
