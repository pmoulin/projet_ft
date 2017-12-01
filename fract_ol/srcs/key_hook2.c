/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:51:16 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:51:33 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		my_key_func2(int keycode, t_env *env)
{
	if (keycode == 53)
		mlx_destroy_window(env->mlx, env->win2);
	return (1);
}
