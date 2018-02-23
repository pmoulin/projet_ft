/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:28:25 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 17:17:53 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_f(double d, int i, t_env *e)
{
	char	*size;
	int		v;

	v = 0;
	e->pos = 0;
	size = NULL;
	if (!(size = ft_ftoa(d)))
		ft_error("FAILL FTOA", "FLAG F");
	free(e->line);
	if (!(e->line = ft_strnew((int)ft_strlen(size) + 1)))
		ft_error("MALLOC_LINE", "FLAG_F");
	while (size[v])
	{
		e->line[(e->pos)] = size[v];
		e->pos++;
		v++;
	}
	e->f = 0;
	free(size);
	return (i);
}
