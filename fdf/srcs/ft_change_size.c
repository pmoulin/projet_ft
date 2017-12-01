/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:40:12 by phmoulin          #+#    #+#             */
/*   Updated: 2017/02/23 10:40:20 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_size_up(t_global *global)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (global->pos[y])
	{
		global->pos[y][x]->x += 5 * x;
		global->pos[y][x]->y += 5 * y;
		x++;
		if (!global->pos[y][x])
		{
			x = 0;
			y++;
		}
	}
}

void		ft_zoom(t_global *global, int keycode)
{
	if (keycode == 69)
		ft_size_up(global);
	ft_gen_map(global, 0);
}
