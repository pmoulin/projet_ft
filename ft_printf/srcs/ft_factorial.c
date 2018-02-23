/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:31:45 by phmoulin          #+#    #+#             */
/*   Updated: 2017/11/03 16:42:05 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	if (nb >= 13 || nb < 0)
		return (0);
	if (nb >= 2)
		return (nb = nb * ft_factorial(nb - 1));
	else if (nb < 3 && nb >= 0)
		return (1);
	return (0);
}
