/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:03:36 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 17:12:52 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		exit_red(int key, t_env *env)
{
	(void)env;
	(void)key;
	exit(0);
}

int		my_key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	if ((key == 2 || key == 0 || key == 1 || key == 13) && env->min_map == -1)
		move_pos_cam(env, key);
	if ((key == 14 || key == 12) && env->min_map == -1)
		move_angle_cam(env, key);
	if (key == 46)
	{
		if (env->min_map == -1)
		{
			gen_mini_map(env);
			env->min_map = 1;
		}
		else
		{
			env->min_map = -1;
			gen_map(env);
		}
	}
	if (key == 48)
	{
		weapon(env, env->weapon.choice_w + 1);
		gen_map(env);
	}
	return (1);
}
