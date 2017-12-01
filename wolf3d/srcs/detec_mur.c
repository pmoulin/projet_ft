/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detec_mur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:26:43 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 17:15:20 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		orientation_ray(t_env *env, int *stepx, int *stepy)
{
	env->cam.distx = sqrt(1 + (env->cam.dr_ry * env->cam.dr_ry) /
			(env->cam.dr_rx * env->cam.dr_rx));
	env->cam.disty = sqrt(1 + (env->cam.dr_rx * env->cam.dr_rx) /
			(env->cam.dr_ry * env->cam.dr_ry));
	*stepx = (env->cam.dr_rx < 0) ? -1 : 1;
	env->cam.size_rx = (env->cam.dr_rx < 0) ? (env->cam.r_px - env->cam.mapx) *
		env->cam.distx : (env->cam.mapx + 1.0 - env->cam.r_px) * env->cam.distx;
	if (env->cam.dr_ry < 0)
	{
		*stepy = -1;
		env->cam.size_ry = (env->cam.r_py - env->cam.mapy) * env->cam.disty;
	}
	else
	{
		*stepy = 1;
		env->cam.size_ry = (env->cam.mapy + 1.0 - env->cam.r_py) *
			env->cam.disty;
	}
}

int				detect_mur(t_env *env, int *stepx, int *stepy)
{
	int		hit;

	hit = 0;
	orientation_ray(env, stepx, stepy);
	while (hit == 0)
	{
		if (env->cam.size_rx <= env->cam.size_ry)
		{
			env->cam.size_rx += env->cam.distx;
			env->cam.mapx += *stepx;
			env->cam.side = (*stepx == 1) ? 0 : -2;
		}
		else
		{
			env->cam.size_ry += env->cam.disty;
			env->cam.mapy += *stepy;
			if (*stepy == -1)
				env->cam.side = 1;
			else
				env->cam.side = -1;
		}
		if (env->map.map[env->cam.mapy][env->cam.mapx] > 48)
			hit = 1;
	}
	return (hit);
}
