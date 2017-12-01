/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:38:07 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 10:22:11 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_fractal(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 46)
		env->frac = 1;
	else if (keycode == 38)
		env->frac = 2;
	else if (keycode == 11)
		env->frac = 3;
	gen_fractal(env);
}

void	fractal(t_env *env, char *param)
{
	if ((ft_strcmp(param, "M")) == 0)
		env->frac = 1;
	else if ((ft_strcmp(param, "J")) == 0)
		env->frac = 2;
	else if ((ft_strcmp(param, "B")) == 0)
		env->frac = 3;
	else
		help();
}
