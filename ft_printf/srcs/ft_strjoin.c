/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:21:04 by phmoulin          #+#    #+#             */
/*   Updated: 2017/08/29 13:21:36 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		d;
	char		*dest;

	d = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s1[d])
	{
		dest[d] = s1[d];
		d++;
	}
	i = 0;
	while (s2[i])
	{
		dest[d] = s2[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (dest);
}
