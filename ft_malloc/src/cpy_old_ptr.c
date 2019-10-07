/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_old_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:15:49 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:15:52 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** ft_strcpy modified
** return ptr(char *)
*/

char		*cpy(char *src, char *dest, size_t size)
{
	size_t		i;

	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0' && i <= size)
		dest[i] = '\0';
	return (dest);
}
