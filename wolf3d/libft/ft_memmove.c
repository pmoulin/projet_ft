/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:16:41 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/15 14:43:29 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;

	if ((tmp = malloc(n)) == NULL)
		return (dest);
	tmp = ft_memcpy(tmp, src, n);
	dest = ft_memcpy(dest, tmp, n);
	free(tmp);
	return (dest);
}
