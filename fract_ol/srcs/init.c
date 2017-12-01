/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:26:41 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:10:44 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_struct(t_env *env)
{
	if (!(env->point = (t_point *)malloc(sizeof(t_point))))
		error(1);
}

void	init_param(t_env *env)
{
	env->key = 0;
	env->x = 0;
	env->y = 0;
	env->on = 1;
	env->point->y = 0;
	env->point->x = 0;
	env->point->x_max = 0.6;
	env->point->x_min = -2.1;
	env->point->y_min = -1.2;
	env->point->y_max = 1.2;
	env->point->zoom = 0.5;
	env->it_m = 100;
	env->point->jic = 0.65186;
	env->point->jrc = 0.0986;
}
