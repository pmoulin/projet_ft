/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:05:06 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/16 14:22:32 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (tab[i][0] != '\0' && i <= len)
	{
		ft_putnbr(i);
		ft_putstr("\t [");
		ft_putstr(tab[i]);
		ft_putstr("]\n");
		i++;
	}
}
