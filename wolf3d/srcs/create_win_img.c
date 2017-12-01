/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:05:21 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 14:13:45 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	create_win_img(t_env *env)
{
	if ((env->win = mlx_new_window(env->mlx, X_W, Y_W, W_N)) == NULL)
		ft_error(5);
	env->img.ptr_img = mlx_new_image(env->mlx, X_S, Y_S);
	env->img.bts_img = mlx_get_data_addr(env->img.ptr_img, &env->img.bpp,
			&env->img.size_l, &env->img.endian);
	if ((env->img_m.ptr_img = mlx_new_image(env->mlx, X_S, Y_S)) == NULL)
		ft_error(5);
	env->img_m.bts_img = mlx_get_data_addr(env->img_m.ptr_img, &env->img_m.bpp,
			&env->img_m.size_l, &env->img_m.endian);
	if ((env->img_me.ptr_img = mlx_new_image(env->mlx, 1000, 100)) == NULL)
		ft_error(5);
	env->img_me.bts_img = mlx_get_data_addr(env->img_me.ptr_img,
		&env->img_me.bpp, &env->img_me.size_l, &env->img_me.endian);
	if ((env->img_ico.ptr_img = mlx_new_image(env->mlx, 1000, 1000)) == NULL)
		ft_error(5);
	env->img_ico.bts_img = mlx_get_data_addr(env->img_ico.ptr_img,
		&env->img_ico.bpp, &env->img_ico.size_l, &env->img_ico.endian);
}
