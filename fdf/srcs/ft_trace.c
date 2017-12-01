/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:23:25 by phmoulin          #+#    #+#             */
/*   Updated: 2017/02/23 09:50:52 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_y(int y, int x, t_point *b, t_global *global)
{
	t_point		a;

	a.y = global->pos[y][x]->y;
	a.x = global->pos[y][x]->x;
	if (global->pos[y + 1] && global->pos[y + 1][x])
	{
		b->x = global->pos[y + 1][x]->x;
		b->y = global->pos[y + 1][x]->y;
	}
	ft_draw_line(global, a, *b, 0x00FFFFFF);
}

static int		init_tab_rx(t_global *global, int key)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (global->pos[y])
	{
		x = 0;
		while (global->pos[y][x])
		{
			ft_matrice(global, key, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

void			ft_trace(t_point *b, t_point *a, t_global *global, int key)
{
	int		y;
	int		x;

	y = 0;
	global->point.radiant = 0.087266462599716;
	(key != 0) ? init_tab_rx(global, key) : 0;
	while (global->pos[y])
	{
		x = 0;
		while (global->pos[y] && global->pos[y][x])
		{
			a->y = global->pos[y][x]->y;
			a->x = global->pos[y][x]->x;
			if (global->pos[y][x + 1])
			{
				b->x = global->pos[y][x + 1]->x;
				b->y = global->pos[y][x + 1]->y;
				ft_draw_line(global, *a, *b, 0x00FFFFFF);
			}
			if (global->pos[y + 1])
				ft_y(y, x, b, global);
			x++;
		}
		y++;
	}
}
