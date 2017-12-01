/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:10:13 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 16:48:49 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		key_one(t_env *env, int key)
{
	if (key == 1)
	{
		if (env->map.map[(int)(env->cam.pcam_y - env->cam.diry *
					env->cam.v_move)][(int)env->cam.pcam_x] != '1')
			env->cam.pcam_y -= env->cam.diry * env->cam.v_move;
		if (env->map.map[(int)env->cam.pcam_y][(int)(env->cam.pcam_x -
					env->cam.dirx * env->cam.v_move)] != '1')
			env->cam.pcam_x -= env->cam.dirx * env->cam.v_move;
	}
	else if (key == 13)
	{
		if (env->map.map[(int)(env->cam.pcam_y + env->cam.diry *
					env->cam.v_move)][(int)env->cam.pcam_x] != '1')
			env->cam.pcam_y += env->cam.diry * env->cam.v_move;
		if (env->map.map[(int)env->cam.pcam_y][(int)(env->cam.pcam_x +
					env->cam.dirx * env->cam.v_move)] != '1')
			env->cam.pcam_x += env->cam.dirx * env->cam.v_move;
	}
}

static void		key_twelve(t_env *env, double oldirx, double oldplx)
{
	oldirx = env->cam.dirx;
	oldplx = env->cam.plx;
	env->cam.dirx = env->cam.dirx * cos(env->cam.v_move) - env->cam.diry *
		sin(env->cam.v_move);
	env->cam.diry = oldirx * sin(env->cam.v_move) + env->cam.diry *
		cos(env->cam.v_move);
	env->cam.plx = env->cam.plx * cos(env->cam.v_move) - env->cam.ply *
		sin(env->cam.v_move);
	env->cam.ply = oldplx * sin(env->cam.v_move) + env->cam.ply *
		cos(env->cam.v_move);
}

void			move_angle_cam(t_env *env, int key)
{
	double oldirx;
	double oldplx;

	oldirx = 0;
	oldplx = 0;
	if (key == 14)
	{
		oldirx = env->cam.dirx;
		oldplx = env->cam.plx;
		env->cam.dirx = env->cam.dirx * cos(-env->cam.v_move) - env->cam.diry
			* sin(-env->cam.v_move);
		env->cam.diry = oldirx * sin(-env->cam.v_move) + env->cam.diry *
			cos(-env->cam.v_move);
		env->cam.plx = env->cam.plx * cos(-env->cam.v_move) - env->cam.ply *
			sin(-env->cam.v_move);
		env->cam.ply = oldplx * sin(-env->cam.v_move) + env->cam.ply *
			cos(-env->cam.v_move);
	}
	else if (key == 12)
		key_twelve(env, oldirx, oldplx);
	gen_map(env);
}

void			move_pos_cam(t_env *env, int key)
{
	if (key == 2)
	{
		if (env->map.map[(int)(env->cam.pcam_y + env->cam.ply *
					env->cam.v_move)][(int)env->cam.pcam_x] != '1')
			env->cam.pcam_y += env->cam.ply * env->cam.v_move;
		if (env->map.map[(int)env->cam.pcam_y][(int)(env->cam.pcam_x +
					env->cam.plx * env->cam.v_move)] != '1')
			env->cam.pcam_x += env->cam.plx * env->cam.v_move;
	}
	else if (key == 0)
	{
		if (env->map.map[(int)(env->cam.pcam_y - env->cam.ply *
					env->cam.v_move)][(int)env->cam.pcam_x] != '1')
			env->cam.pcam_y -= env->cam.ply * env->cam.v_move;
		if (env->map.map[(int)env->cam.pcam_y][(int)(env->cam.pcam_x -
					env->cam.plx * env->cam.v_move)] != '1')
			env->cam.pcam_x -= env->cam.plx * env->cam.v_move;
	}
	else if (key == 1)
		key_one(env, key);
	else if (key == 13)
		key_one(env, key);
	gen_map(env);
}
