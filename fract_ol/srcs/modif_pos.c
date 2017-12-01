/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:43:34 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 16:20:30 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		modif_x(t_env *env, int key)
{
	if (key == 123)
		env->point->x += 10;
	if (key == 124)
		env->point->x -= 10;
	gen_fractal(env);
}

static void		modif_y(t_env *env, int key)
{
	if (key == 126)
		env->point->y += 10;
	if (key == 125)
		env->point->y -= 10;
	gen_fractal(env);
}

void			modif_pos(t_env *env, int key)
{
	if (key == 123 || key == 124)
		modif_x(env, key);
	else if (key == 125 || key == 126)
		modif_y(env, key);
}
