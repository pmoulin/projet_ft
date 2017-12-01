/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:49:54 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 16:24:30 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		compare_size_l(t_env *env, int y)
{
	while (env->map.map[y + 1])
	{
		if (ft_strlen(env->map.map[y]) != ft_strlen(env->map.map[y + 1]))
			ft_error(3);
		else
			y++;
	}
}

static void		check_bord_map(t_env *env, int y, int x)
{
	while (env->map.map[0][x])
	{
		(env->map.map[0][x] != '1') ? ft_error(3) : 0;
		x++;
	}
	while (env->map.map[y])
	{
		if (env->map.map[y][x - 1] != '1')
			ft_error(3);
		y++;
	}
	y = 0;
	while (env->map.map[y])
	{
		if (env->map.map[y][0] != '1')
			ft_error(3);
		y++;
	}
	x = 0;
	while (env->map.map[y - 1][x])
	{
		if (env->map.map[y - 1][x] != '1')
			ft_error(3);
		x++;
	}
}

static void		check_carac_map(t_env *env, int y, int x)
{
	while (env->map.map[y])
	{
		if (env->map.map[y][x] != '1' && env->map.map[y][x] != '0' &&
			env->map.map[y][x] != '3')
			ft_error(3);
		x++;
		if (!env->map.map[y][x])
		{
			y++;
			x = 0;
		}
	}
}

static void		check_pos_start(t_env *env, int y, int x)
{
	while (env->map.map[y])
	{
		if (cordo_start(env, x, y) == 1)
			break ;
		x++;
		if (env->map.map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	if (env->cam.pcam_x == -10)
		ft_error(3);
}

void			check_map(t_env *env)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	compare_size_l(env, y);
	check_carac_map(env, y, x);
	check_bord_map(env, y, x);
	check_pos_start(env, y, x);
}
