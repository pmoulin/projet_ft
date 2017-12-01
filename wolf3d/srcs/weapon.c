/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 10:52:01 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 14:54:59 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	weapon(t_env *env, int i)
{
	env->weapon.choice_w = i;
	if (env->weapon.choice_w > 2)
	{
		i = 0;
		env->weapon.choice_w = i;
	}
	if (env->weapon.ptr_img)
		env->weapon.ptr_img = NULL;
	if ((env->weapon.ptr_img = mlx_xpm_file_to_image(env->mlx,
			env->weapon.path_w[i], &env->weapon.x, &env->weapon.y)) == NULL)
		ft_error(4);
	if (env->weapon.bts_img)
		ft_strdel(&env->weapon.bts_img);
	if ((env->weapon.bts_img = mlx_get_data_addr(env->weapon.ptr_img,
			&env->weapon.bpp, &env->weapon.size_l,
			&env->weapon.endian)) == NULL)
		ft_error(4);
	weapon_select(env);
}
