/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:47:51 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/15 11:26:04 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			x;
	char			*destcpy;
	const char		*srccpy;

	srccpy = src;
	destcpy = dest;
	i = 0;
	x = 0;
	while (x < n && i < n)
	{
		destcpy[i] = (char)srccpy[x];
		i++;
		x++;
	}
	return (dest);
}
