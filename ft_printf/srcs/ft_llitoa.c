/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:38:01 by phmoulin          #+#    #+#             */
/*   Updated: 2017/11/26 15:05:12 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		nb_elem(long long int n)
{
	int						i;
	unsigned long long int	nb;

	nb = (n < 0) ? -n : n;
	i = 0;
	while (nb / 10 > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static	char	*ft_calcule(char *dest, int i, long long int a, int d)
{
	unsigned long long int nb;

	nb = (a < 0) ? -a : a;
	while (nb)
	{
		dest[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (dest);
}

static char		*ft_unit(char *dest, int i, int a)
{
	dest[i] = a + 48;
	dest[i + 1] = '\0';
	return (dest);
}

char			*ft_llitoa(unsigned long long int n)
{
	int						i;
	int						d;
	unsigned long long int	a;
	char					*dest;
	int						nega;

	a = (n < 0) ? -n : n;
	nega = ((long long int)n > 0) ? 0 : 1;
	i = 0;
	d = nb_elem(a);
	if ((dest = (char *)malloc((d + nega + 1) * sizeof(dest))) == NULL)
		return (NULL);
	if (nega != 0)
		dest[0] = '-';
	if (n <= 9)
		return (ft_unit(dest, i, a));
	i = d + nega;
	dest = ft_calcule(dest, i, (long long int)a, d);
	dest[d + nega + 1] = '\0';
	return (dest);
}
