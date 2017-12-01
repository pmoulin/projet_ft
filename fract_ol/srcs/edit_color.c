/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:45:08 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:50:41 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			edit_color(t_env *env, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y > 0 && x > 0 && y < Y_SIZE && x < X_SIZE)
	{
		env->img->bts_img[(y * env->img->size_l) + \
			((env->img->bpp / 8) * x) + 2] = r;
		env->img->bts_img[(y * env->img->size_l) + \
			((env->img->bpp / 8) * x) + 1] = g;
		env->img->bts_img[(y * env->img->size_l) + \
			((env->img->bpp / 8) * x)] = b;
	}
}
