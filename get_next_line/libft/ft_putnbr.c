/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:50:38 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/14 15:29:55 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	*str;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		str = ft_itoa(n);
		write(1, str, ft_strlen(str));
	}
}
