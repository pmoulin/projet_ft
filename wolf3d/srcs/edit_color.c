/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:45:08 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 23:21:38 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			edit_color_mini_map(t_env *env, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < Y_S && x < X_S)
	{
		env->img_m.bts_img[(y * env->img_m.size_l) + \
			((env->img_m.bpp / 8) * x) + 2] = r;
		env->img_m.bts_img[(y * env->img_m.size_l) + \
			((env->img_m.bpp / 8) * x) + 1] = g;
		env->img_m.bts_img[(y * env->img_m.size_l) + \
			((env->img_m.bpp / 8) * x)] = b;
	}
}

void			edit_color(t_env *env, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < Y_S && x < X_S)
	{
		env->img.bts_img[(y * env->img.size_l) + \
			((env->img.bpp / 8) * x) + 2] = r;
		env->img.bts_img[(y * env->img.size_l) + \
			((env->img.bpp / 8) * x) + 1] = g;
		env->img.bts_img[(y * env->img.size_l) + \
			((env->img.bpp / 8) * x)] = b;
	}
}

void			edit_color_ico(t_env *env, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < Y_S && x < X_S)
	{
		env->img_ico.bts_img[(y * env->img_ico.size_l) + \
			((env->img_ico.bpp / 8) * x) + 2] = r;
		env->img_ico.bts_img[(y * env->img_ico.size_l) + \
			((env->img_ico.bpp / 8) * x) + 1] = g;
		env->img_ico.bts_img[(y * env->img_ico.size_l) + \
			((env->img_ico.bpp / 8) * x)] = b;
	}
}

void			edit_color_me(t_env *env, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < Y_S && x < X_S)
	{
		env->img_me.bts_img[(y * env->img_me.size_l) + \
			((env->img_me.bpp / 8) * x) + 2] = r;
		env->img_me.bts_img[(y * env->img_me.size_l) + \
			((env->img_me.bpp / 8) * x) + 1] = g;
		env->img_me.bts_img[(y * env->img_me.size_l) + \
			((env->img_me.bpp / 8) * x)] = b;
	}
}
