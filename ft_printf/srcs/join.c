/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:26:12 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 17:29:42 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			join(char *tmp, t_env *e, char *tmp2)
{
	int		i;
	int		v;
	int		z;

	i = 0;
	v = 0;
	z = 0;
	while (tmp[v])
		e->line[i++] = tmp[v++];
	while (tmp2[z])
		e->line[i++] = tmp2[z++];
	e->pos = i;
	e->line[e->pos] = '\0';
}
