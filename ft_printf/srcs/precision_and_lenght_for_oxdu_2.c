/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_and_lenght_for_oxdu_2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:18:29 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 13:54:20 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	preci_and_lenght_for_oxdu_6(t_env *e, char *tmp, int t, int x)
{
	int		v;
	int		i;

	i = 0;
	v = 0;
	if (t > e->t2)
		while (i < t - (x + e->plus))
			tmp[i++] = ' ';
	if (e->t2 > x)
		while (i < (e->t2 - x) + e->plus)
			tmp[i++] = '0';
	if (e->nega == 1)
	{
		if (e->t2 > x)
			i = (e->plus == 1) ? t - e->t2 - e->plus : t - e->t2 - e->n;
		i -= (t > x && e->t2 < x) ? 1 : 0;
		tmp[i++] = '-';
	}
	if (e->t2 > x)
	{
		i = (e->plus == 1) ? t - e->t2 - e->plus : t - e->t2 - e->n;
		(e->nega == 1) ? tmp[i - 1] = '-' : 0;
		(e->plus == 1) ? tmp[i++] = '+' : 0;
	}
	return (i);
}

static int	preci_and_lenght_for_oxdu_5(t_env *e, int x, char *param, char *tmp)
{
	int		i;
	int		v;
	int		t;

	v = 0;
	i = 0;
	t = (e->t < 0) ? -e->t : e->t;
	if (e->nega == 1)
		tmp[i++] = '-';
	else if (e->nega == 0 && e->plus == 1)
		tmp[i++] = '+';
	if (e->t2 > x && e->plus == 1 && e->h_tag == 0)
		tmp[i++] = '0';
	if (t > e->t2)
		while (param[v])
			tmp[i++] = param[v++];
	while (i < t)
		tmp[i++] = e->carac;
	return (i);
}

void		preci_and_lenght_for_oxdu_4(t_env *e, char *param, char *tmp, int x)
{
	int		i;
	int		t;
	int		i1;
	int		v;

	v = 0;
	t = (e->t < 0) ? -e->t : e->t;
	i = 0;
	i1 = 0;
	if (e->n == 1)
		i = preci_and_lenght_for_oxdu_5(e, x, param, tmp);
	else if (e->n == 0)
	{
		i = preci_and_lenght_for_oxdu_6(e, tmp, t, x);
		if (e->t2 > x)
			while (v++ < e->t2 - x)
				tmp[i++] = '0';
		while (param[i1])
			tmp[i++] = param[i1++];
	}
}
