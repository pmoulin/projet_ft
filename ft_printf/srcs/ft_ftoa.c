/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:45:30 by phmoulin          #+#    #+#             */
/*   Updated: 2017/11/03 15:59:50 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_join(char *str, char *tmp)
{
	int		i;
	int		a;
	char	*tmp2;

	a = 0;
	tmp2 = NULL;
	tmp2 = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(tmp) + 2));
	i = 0;
	while (str[i])
		tmp2[a++] = str[i++];
	i = 0;
	tmp2[a] = '.';
	a++;
	while (tmp[i])
		tmp2[a++] = tmp[i++];
	tmp2[a] = '\0';
	return (tmp2);
}

char			*ft_ftoa(double nb)
{
	char		*str;
	char		*tmp;
	char		*tmp2;
	double		i;
	intmax_t	v;

	str = NULL;
	tmp = NULL;
	v = (intmax_t)nb;
	i = (nb - v);
	i = (i < 0) ? -i : i;
	i += (i == (int)i) ? 0 : 0.0000001;
	i *= 1000000;
	str = ft_llitoa((intmax_t)v);
	tmp = ft_ullitoa((intmax_t)i);
	tmp2 = ft_join(str, tmp);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (tmp2);
}
