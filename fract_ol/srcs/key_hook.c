/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:10:42 by phmoulin          #+#    #+#             */
/*   Updated: 2017/04/28 10:40:34 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		re_init_img(t_env *env)
{
	ft_bzero(env->img->bts_img, ft_strlen(env->img->bts_img));
	mlx_destroy_image(env->mlx, env->img->ptr_img);
	env->img->ptr_img = mlx_new_image(env->mlx, X_SIZE, Y_SIZE);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &env->img->bpp,
		&env->img->size_l, &env->img->endian);
}

int				my_key_func(int keycode, t_env *env)
{
	re_init_img(env);
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 || keycode == 84 || keycode == 78 || keycode == 83)
		zoom(env, keycode);
	if (keycode == 6)
		gen_fractal(env);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		modif_pos(env, keycode);
	if (keycode == 50)
		reset(env);
	if (keycode == 17)
	{
		if (env->key == 0)
			env->key = 1;
		else
			env->key = 0;
	}
	if (keycode == 46 || keycode == 38 || keycode == 11)
		change_fractal(env, keycode);
	return (1);
}

int				mouse_func(int keycode, int x, int y, t_env *env)
{
	re_init_img(env);
	x -= X_SIZE / 2;
	y -= Y_SIZE / 2;
	if (keycode == 5)
		zoom_param(env, 1, x, y);
	else if (keycode == 4)
		zoom_param(env, 0, x, y);
	return (1);
}

int				mouse_code(int x, int y, t_env *env)
{
	if (env->key == 1)
	{
		re_init_img(env);
		env->point->jic = y / (env->point->zoom + 100) + env->point->y_min;
		env->point->jrc = x / (env->point->zoom + 100) + env->point->x_min;
		env->point->jrc /= 10;
		gen_fractal(env);
	}
	return (1);
}
