/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:38:01 by phmoulin          #+#    #+#             */
/*   Updated: 2017/11/25 16:36:15 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		nb_elem(unsigned int n)
{
	int		i;

	i = 0;
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	char	*ft_calcule(char *dest, int i, unsigned int a, int d)
{
	while (a / 10 > 0)
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

char			*ft_uitoa(unsigned int n)
{
	int				i;
	int				d;
	unsigned int	a;
	char			*dest;
	int				nega;

	a = n;
	i = 0;
	nega = ((long long int)n > 0) ? 0 : 1;
	d = nb_elem(a);
	if ((dest = (char *)malloc((d + 1) * sizeof(dest))) == NULL)
		return (NULL);
	if (n <= 9)
		return (ft_unit(dest, i, a));
	i = d;
	dest = ft_calcule(dest, i, a, d);
	return (dest);
}
