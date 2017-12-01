/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:22:17 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/14 18:33:14 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = ((s[i] && s[i] != c) ? 1 : 0);
	while (s[i])
	{
		if (s[i] && s[i + 1] != c && s[i + 1] != '\0')
			w++;
		i++;
	}
	return (w);
}
