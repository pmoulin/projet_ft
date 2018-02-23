/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:38:01 by phmoulin          #+#    #+#             */
/*   Updated: 2017/11/03 11:52:25 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_elem(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	char	*ft_calcule(char *dest, int i, unsigned int a, int d)
{
	while (a)
	{
		dest[i] = (a % 10) + 48;
		a = a / 10;
		i--;
	}
	dest[d + 1] = '\0';
	return (dest);
}

static char		*ft_unit(char *dest, int i, int a)
{
	dest[i] = a + 48;
	dest[i + 1] = '\0';
	return (dest);
}

char			*ft_itoa(int n)
{
	int				i;
	int				d;
	unsigned int	a;
	char			*dest;

	a = n;
	i = 0;
	d = nb_elem(a);
	if ((dest = (char *)malloc((d + 1) * sizeof(dest))) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(dest, "-2147483648"));
	if (n < 0)
	{
		a = -n;
		dest[i] = '-';
		i++;
	}
	if (n >= 0 && n <= 9)
		return (ft_unit(dest, i, a));
	i = d;
	dest = ft_calcule(dest, i, a, d);
	return (dest);
}
