/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:48:51 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 23:21:54 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		init_param_map(t_env *env)
{
	env->map.line = 0;
	env->map.map = NULL;
	env->cam.pcam_x = -10;
	env->cam.pcam_y = -10;
	env->cam.dirx = -1;
	env->cam.diry = 0;
	env->cam.ply = 1;
	env->cam.plx = 0;
	env->cam.side = 0;
	env->min_map = -1;
}

void			init_param_cam(t_env *env, int x)
{
	if (env->cam.movex > 1 && env->cam.movex < -1)
		env->cam.movex = 0;
	else if (env->cam.movey > 1 && env->cam.movey < -1)
		env->cam.movey = 0;
	env->cam.v_move = 0.2;
	env->cam.camx = (2.0 * x / X_S) - 1;
	env->cam.r_px = env->cam.pcam_x;
	env->cam.r_py = env->cam.pcam_y;
	env->cam.dr_rx = env->cam.dirx + (env->cam.plx * env->cam.camx);
	env->cam.dr_ry = env->cam.diry + (env->cam.ply * env->cam.camx);
	env->cam.mapy = (int)env->cam.r_py;
	env->cam.mapx = (int)env->cam.r_px;
}

static void		init_weapon(t_env *env)
{
	env->weapon.path_w[0] = "images/aka_p.xpm";
	env->weapon.path_w[1] = "images/knif_p.xpm";
	env->weapon.path_w[2] = "images/snipe_p.xpm";
	env->weapon.choice_w = 0;
}

void			init_struct(t_env *env, int choice)
{
	if (choice == 1)
		init_param_map(env);
	else if (choice == 2)
		init_weapon(env);
}
