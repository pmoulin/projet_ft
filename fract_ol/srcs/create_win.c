/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:57:06 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:11:23 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_win(t_env *env)
{
	if (!(env->img = malloc(sizeof(t_img))))
		error(1);
	env->win = mlx_new_window(env->mlx, X_SIZE, Y_SIZE, W_NAME);
	env->win2 = mlx_new_window(env->mlx, 655, 480, "fractol guide");
	help_win(env);
	env->img->ptr_img = mlx_new_image(env->mlx, X_SIZE, Y_SIZE);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &env->img->bpp,
		&env->img->size_l, &env->img->endian);
}
