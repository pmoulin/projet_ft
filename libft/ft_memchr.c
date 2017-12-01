/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:16:21 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/15 11:41:26 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (ptr[i] != (unsigned char)c)
			i++;
		else
			return ((void *)&ptr[i]);
	}
	return (NULL);
}
