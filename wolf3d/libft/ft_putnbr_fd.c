/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr-fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:15:59 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/14 16:45:00 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		str = ft_itoa(n);
		write(fd, str, ft_strlen(str));
	}
}