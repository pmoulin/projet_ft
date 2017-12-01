/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:59:28 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/16 12:29:48 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	if (!s || !f)
		return (NULL);
	res = ft_memalloc((size_t)ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	if (s && (*f))
	{
		while (s[i])
		{
			res[i] = (*f)(s[i]);
			i++;
		}
		res[i] = 0;
	}
	return (res);
}
