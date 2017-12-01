/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 16:40:26 by phmoulin          #+#    #+#             */
/*   Updated: 2016/07/08 13:34:51 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		d;
	char	tempon;
	char	tempon2;

	i = 0;
	d = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (d < i || d == i)
	{
		tempon = str[d];
		tempon2 = str[i];
		str[d] = tempon2;
		str[i] = tempon;
		i--;
		d++;
	}
	return (str);
}
