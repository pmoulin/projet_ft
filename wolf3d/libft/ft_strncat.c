/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:41:59 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/05 12:43:05 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		t_dest;
	int		t_src;

	t_dest = 0;
	t_src = 0;
	t_dest = ft_strlen(dest);
	while (src[t_src] != 0 && n > 0)
	{
		dest[t_dest] = src[t_src];
		t_dest++;
		t_src++;
		n--;
	}
	dest[t_dest] = '\0';
	return (dest);
}
