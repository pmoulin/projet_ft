/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_menu_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:35:31 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/11 12:32:42 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	gen_menu_down(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 10, Y_S, 0x00FFFFFF,
			"Mouvement : 'W S A D' | Rotation 'Q R'");
	mlx_string_put(env->mlx, env->win, 10, Y_S + 50, 0x00FFFFFF,
			"Affichage de la map 'M' && 'TAB' change arme");
}
