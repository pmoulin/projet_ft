/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:47:21 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/05 13:14:24 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	t_dest;
	int	t_src;

	t_dest = 0;
	t_src = 0;
	t_dest = ft_strlen(dest);
	while (src[t_src] != '\0')
	{
		dest[t_dest] = src[t_src];
		t_dest++;
		t_src++;
	}
	dest[t_dest] = '\0';
	return (dest);
}
