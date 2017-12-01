/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:41:13 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:53:10 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		profondeur_it(t_env *env, int x, int y)
{
	double		rz;

	while ((env->point->rz * env->point->rz) +
			(env->point->iz * env->point->iz) < 4 && env->point->a < env->it_m)
	{
		rz = (env->point->rz * env->point->rz)
			- (env->point->iz * env->point->iz) + env->point->rc;
		env->point->iz = 2 * env->point->rz * env->point->iz + env->point->ic;
		env->point->rz = rz;
		env->point->a += 1;
	}
	if (env->point->a == env->it_m)
		edit_color(env, x, y, 0x00FD6C9E);
	else
		edit_color(env, x, y, env->point->a * 255 / 100);
}

void			mandel(t_env *env, int y, int x)
{
	while (y++ < Y_SIZE)
	{
		x = 0;
		while (x++ < X_SIZE)
		{
			env->point->a = 1;
			env->point->iz = 0;
			env->point->rz = 0;
			env->point->rc = 1.5 * (x + env->point->x - X_SIZE / 2) /
				(0.5 * env->point->zoom * X_SIZE) +
				(env->x / X_SIZE / 1.37) - 0.5;
			env->point->ic = (y + env->point->y - Y_SIZE / 2) / (0.5 *
				env->point->zoom * Y_SIZE) - (env->y / Y_SIZE / 1.92);
			profondeur_it(env, x, y);
		}
	}
}
