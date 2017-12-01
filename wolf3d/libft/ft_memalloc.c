/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:36:47 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/16 11:27:23 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t		*p;

	if ((p = (void *)malloc((size) * sizeof(void))) == NULL)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
