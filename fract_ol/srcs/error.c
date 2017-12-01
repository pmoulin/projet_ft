/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:20:34 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:13:48 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error(int error)
{
	if (error == 1)
		ft_putstr("ERROR : PARAM INVALIDE");
	if (error == 2)
		ft_putstr("ERROR : MALLOC");
	if (error == 4)
		ft_putstr("ERROR : ");
	if (error == 5)
		ft_putstr("ERROR :");
	if (error == 6)
		ft_putstr("ERROR :");
	exit(0);
}
