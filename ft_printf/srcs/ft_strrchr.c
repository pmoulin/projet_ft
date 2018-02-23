/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:14:38 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/14 12:48:40 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		x;

	i = ft_strlen(s);
	x = i;
	if ((char)c == '\0' && s)
		return ((char *)&s[i]);
	while (s[i] != (char)c && i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	if (i <= 0)
		return (NULL);
	return ((char *)&s[i]);
}
