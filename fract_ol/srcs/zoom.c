/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:56:38 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 16:17:58 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		it_up(t_env *env)
{
	env->it_m += 10;
}

static void		it_down(t_env *env)
{
	if (env->it_m > 10)
		env->it_m -= 10;
}

void			zoom_param(t_env *env, int key, int x, int y)
{
	if (key == 1)
	{
		env->point->zoom *= 2.1;
		env->x += x / env->point->zoom / 0.21;
		env->y -= y / env->point->zoom / 0.21;
		env->it_m += 10;
	}
	else if (key == 0 && env->point->zoom > 0)
	{
		env->point->zoom /= 2.1;
		env->it_m -= 10;
	}
	gen_fractal(env);
}

void			zoom(t_env *env, int key)
{
	if (key == 69)
		zoom_param(env, 1, 0, 0);
	else if (key == 84)
		it_up(env);
	else if (key == 83)
		it_down(env);
	else if (key == 78)
		zoom_param(env, 0, 0, 0);
	gen_fractal(env);
}
