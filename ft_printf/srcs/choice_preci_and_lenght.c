/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_preci_and_lenght.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 11:57:20 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 16:07:28 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		choice_preci_and_lenght_for_p(t_env *e, char *param)
{
	if (e->t != 0 || e->t2 != 0)
	{
		if (e->t != 0 && e->tv[0] != 0 && (e->tv[1] == 0 || e->t2 == 0))
			lenght_for_p(e, param, 0);
		if ((e->tv[0] == 0 || e->t == 0) && (e->t2 != 0 && e->tv[1] != 0))
			preci_for_p(e, param, 0);
		else if (e->tv[0] != 0 && e->tv[1] != 0 && e->t != 0 && e->t2 != 0)
			lenght_and_preci_for_p_1(e, param, 0);
	}
}

void		choice_preci_and_lenght_for_oxdu(t_env *e, char *param)
{
	if (e->t != 0 || e->t2 != 0)
	{
		if (e->t != 0 && e->tv[0] != 0 && (e->tv[1] == 0 || e->t2 == 0))
			lenght_for_oxdu(e, param, 0);
		if ((e->tv[0] == 0 || e->t == 0) && (e->t2 != 0 && e->tv[1] != 0))
			precision_for_oxdu(e, param, 0);
		else if (e->tv[0] != 0 && e->tv[1] != 0 && e->t != 0 && e->t2 != 0)
			precision_and_lenght_for_oxdu(e, param, 0);
	}
}

void		choice_precision_and_lenght_for_s(t_env *e, char *param)
{
	int		i;

	i = 0;
	if (e->t != 0 || e->t2 != 0)
	{
		if (e->t != 0 && e->tv[0] != 0 && (e->tv[1] == 0 || e->t2 == 0))
			lenght_for_s(e, param);
		if ((e->tv[0] == 0 || e->t == 0) && (e->t2 != 0 && e->tv[1] != 0))
			precision_for_s(e, param, 0);
		else if (e->tv[0] != 0 && e->tv[1] != 0 && e->t != 0 && e->t2 != 0)
			precision_and_lenght_for_s(e, param, 0);
	}
}
