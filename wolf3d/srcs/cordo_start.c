/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 13:07:14 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 17:14:21 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		cordo_start(t_env *env, int x, int y)
{
	if (env->map.map[y][x] == '0' && env->map.map[y][x + 1] == '0' &&
		env->map.map[y][x - 1] == '0' && env->map.map[y + 1][x] == '0' &&
		env->map.map[y - 1][x] == '0' && env->map.map[y + 1][x + 1] == '0' &&
		env->map.map[y - 1][x + 1] == '0' && env->map.map[y - 1][x - 1] == '0'
		&& env->map.map[y + 1][x - 1] == '0')
	{
		env->cam.pcam_y = y + 0.5;
		env->cam.pcam_x = x + 0.5;
		return (1);
	}
	else
		return (0);
}
