/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:32:10 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/06 18:00:58 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		t;
	int		x;

	x = 0;
	i = 0;
	t = 0;
	while (s1[i] && s2[x])
	{
		t = i;
		x = 0;
		while (s1[t] == s2[x] && s1[t] && s2[x])
		{
			t++;
			x++;
		}
		if (s2[x] != '\0')
			i++;
	}
	if (s2[0] == '\0')
		return ((char *)s1);
	else if (s1[i] && s2[x] == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}
