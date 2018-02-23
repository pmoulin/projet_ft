/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_unsi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:41:14 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 15:19:15 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flag_u(unsigned long long int nb, int i, t_env *e, int x2)
{
	char		*tmp;

	tmp = NULL;
	if (nb == 0 && e->t == 0 && e->t2 == 0 && ((e->tv[0] != 0 || e->tv[1] != 0)
	|| e->point != 0))
		return (i);
	if ((e->type_convert[0] != '*') || (e->u == 2 && e->type_convert[0] != 'h'
	&& e->type_convert[1] != 'h') && x2 != 42)
		tmp = ft_ullitoa((unsigned long long int)nb);
	else if (e->type_convert[0] == 'h' && x2 != 42)
		tmp = ft_llitoa((long long int)nb);
	else if (e->type_convert[0] == '*' && x2 != 42)
		tmp = ft_ullitoa((unsigned int)nb);
	else if (x2 == 42)
		tmp = ft_ullitoa((unsigned long long int)nb);
	if (e->t != 0 || e->t2 != 0)
		choice_preci_and_lenght_for_oxdu(e, tmp);
	else
		e->line = ft_strdup(tmp);
	free(tmp);
	return (i);
}
