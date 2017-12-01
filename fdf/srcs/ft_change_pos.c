/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:02:00 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/20 20:18:17 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_change_pos_r(t_global *global)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (global->pos[y])
	{
		global->pos[y][x]->x += 5;
		x++;
		if (!global->pos[y][x])
		{
			y++;
			x = 0;
		}
	}
}

static void	ft_change_pos_l(t_global *global)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (global->pos[y])
	{
		global->pos[y][x]->x -= 5;
		x++;
		if (!global->pos[y][x])
		{
			y++;
			x = 0;
		}
	}
}

static void	ft_change_pos_u(t_global *global)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (global->pos[y])
	{
		global->pos[y][x]->y += 5;
		x++;
		if (!global->pos[y][x])
		{
			y++;
			x = 0;
		}
	}
}

static void	ft_change_pos_d(t_global *global)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (global->pos[y])
	{
		global->pos[y][x]->y -= 5;
		x++;
		if (!global->pos[y][x])
		{
			y++;
			x = 0;
		}
	}
}

void		ft_change_pos(t_global *global, int key)
{
	if (key == 124)
		ft_change_pos_r(global);
	else if (key == 123)
		ft_change_pos_l(global);
	else if (key == 125)
		ft_change_pos_u(global);
	else if (key == 126)
		ft_change_pos_d(global);
	ft_gen_map(global, 0);
}
