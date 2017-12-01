/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_mur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:57:16 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 17:20:44 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		color_mur(t_env *env, int x, int y)
{
	if (env->cam.side == 1)
		edit_color(env, (int)x, (int)y, 0x00FFFFFF);
	else
	{
		if (env->map.map[env->cam.mapy][env->cam.mapx] == '3')
			edit_color(env, (int)x, (int)y, 0x000000FF);
		else if (env->cam.side == 0)
			edit_color(env, (int)x, (int)y, 0x00FFFF00);
		if (env->cam.side == -1)
			edit_color(env, (int)x, (int)y, 0x00000000);
		else if (env->cam.side == -2)
			edit_color(env, (int)x, (int)y, 0x00FF10F0);
	}
}

void			aff_mur(t_env *env, int x, double wall_dist)
{
	int		y;
	int		drawend;
	int		drawstart;
	int		hauteurligne;

	hauteurligne = ABS((int)(Y_S / wall_dist));
	drawstart = -hauteurligne / 2 + Y_S / 2;
	drawend = hauteurligne / 2 + Y_S / 2;
	if (drawstart < 0)
		drawstart = 0;
	if (drawend > Y_S)
		drawend = Y_S - 1;
	y = drawstart - 2;
	while (y++ <= drawend)
		color_mur(env, x, y);
	if (drawend < 0)
		drawend = Y_S;
	y = drawend;
	while (y < Y_S)
	{
		edit_color(env, (int)x, Y_S - y - 2, 0x00FE1B00);
		edit_color(env, (int)x, y, 0x00808080);
		y++;
	}
}
