/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_frac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:54:42 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:50:57 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	gen_fractal(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (env->frac == 1)
		mandel(env, y, x);
	else if (env->frac == 2)
		julia(env, y, x);
	else if (env->frac == 3)
		burn_ship(env, y, x);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
}
