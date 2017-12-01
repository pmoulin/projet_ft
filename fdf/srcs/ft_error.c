/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:20:34 by phmoulin          #+#    #+#             */
/*   Updated: 2017/02/22 11:15:22 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(int error)
{
	if (error == 1)
		ft_putstr("ERROR : PARAM INVALIDE");
	if (error == 2)
		ft_putstr("ERROR : MALLOC");
	if (error == 3)
		ft_putstr("ERROR : FILE IS NOT VALID");
	if (error == 4)
		ft_putstr("ERROR : ");
	if (error == 5)
		ft_putstr("ERROR :");
	if (error == 6)
		ft_putstr("ERROR :");
	exit(0);
}
