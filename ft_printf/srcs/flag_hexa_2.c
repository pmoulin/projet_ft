/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hexa_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:55:36 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 14:00:44 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_nb_to_letter(int *i2, char type)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_memalloc(2);
	if (type == 'x')
		tmp[0] = BASEA[*i2];
	else
		tmp[0] = BASEB[*i2];
	tmp[1] = '\0';
	return (tmp);
}

void	free_tab(char **tmp, int x)
{
	x -= 1;
	while (x >= 0)
		free(tmp[x--]);
}

int		nb_zero_or_one(t_env *e, int i, unsigned long long int nb)
{
	if (nb == 1)
	{
		if (!(e->line = ft_strnew(1)))
			ft_error("LINE", "LAG_X");
		e->line[0] = '1';
	}
	if (nb == 0)
	{
		if (e->tv[0] == 0 && e->point == 0)
		{
			if (!(e->line = ft_strnew(1)))
				ft_error("LINE", "LAG_X");
			e->line[0] = '0';
		}
		else
			e->line = NULL;
	}
	e->x = 0;
	return (i);
}
