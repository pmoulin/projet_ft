/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:13:45 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 17:14:53 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		aff_mur1(t_env *env)
{
	int			x;
	int			stepx;
	int			stepy;
	double		wall_dist;

	wall_dist = 1;
	x = 0;
	while (x <= X_S)
	{
		init_param_cam(env, x);
		detect_mur(env, &stepx, &stepy);
		if (env->cam.side == 0 || env->cam.side == -2)
			wall_dist = ABS((env->cam.mapx - env->cam.r_px + (1 - stepx) / 2) /
				env->cam.dr_rx);
		else if (env->cam.side == 1 || env->cam.side == -1)
			wall_dist = ABS((env->cam.mapy - env->cam.r_py + (1 - stepy) / 2) /
				env->cam.dr_ry);
		aff_mur(env, x, wall_dist);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr_img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->weapon.ptr_img, X_S -
		env->weapon.x, Y_S - env->weapon.y);
}

void			gen_map(t_env *env)
{
	aff_mur1(env);
}
