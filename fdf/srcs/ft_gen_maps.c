/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:10:07 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/20 19:57:12 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_gen_win(t_global *global)
{
	global->env->win = mlx_new_window(global->env->mlx, Y_SIZE, X_SIZE, W_NAME);
}

void			ft_gen_img(t_global *global, int key)
{
	global->img = malloc(sizeof(t_img));
	global->img->ptr_img = mlx_new_image(global->env->mlx, Y_SIZE, X_SIZE);
	global->img->bts_img = mlx_get_data_addr(global->img->ptr_img,
			&global->img->bpp, &global->img->size_l, &global->img->endian);
	ft_gen_map(global, key);
}

void			ft_gen_map(t_global *global, int key)
{
	t_point		a;
	t_point		b;

	ft_trace(&b, &a, global, key);
	mlx_put_image_to_window(global->env->mlx,
			global->env->win, global->img->ptr_img, 0, 0);
}

void			ft_put_img(t_global *global, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y > 0 && x > 0 && y < 1000 && x < 1000)
	{
		global->img->bts_img[(y * global->img->size_l) + \
		((global->img->bpp / 8) * x) + 2] = r;
		global->img->bts_img[(y * global->img->size_l) + \
		((global->img->bpp / 8) * x) + 1] = g;
		global->img->bts_img[(y * global->img->size_l) + \
		((global->img->bpp / 8) * x)] = b;
	}
}
