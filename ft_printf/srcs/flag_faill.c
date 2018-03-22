/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_faill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 09:58:14 by phmoulin          #+#    #+#             */
/*   Updated: 2018/03/10 13:54:37 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_modu(int i, t_env *e)
{
	int			v;
	int			i1;

	i1 = 0;
	v = (e->t < 0) ? -e->t : e->t;
	if (!(e->line = ft_strnew(v + 2)))
		ft_error("MALLOC_LINEone", "FLAG_MODU malloc one");
	if (v != 0)
	{
		if (e->t < 0)
			e->line[i1++] = '%';
		while (i1 <= v - 1)
			e->line[i1++] = e->carac;
		if (e->t > 0)
			e->line[i1 - 1] = '%';
	}
	else if (v == 0)
		e->line[i1] = '%';
	e->modulo = 0;
	return (i);
}

int	printf_faill_param(t_env *e, const char *restrict format, int i, int i1)
{
	int		x;
	int		t;

	t = (e->t < 0) ? -e->t : e->t;
	t = (t == 0) ? 1 : t;
	i1 = 1;
	x = 0;
	if (!(e->line = ft_strnew(t)))
		ft_error("MALLOC_LINE", "print faill param");
	if (e->t == 0 && e->t2 == 0)
		e->line[0] = format[i];
	if (e->t != 0 && e->t2 == 0)
	{
		if (e->t < 0 && e->t2 == 0 && e->point == 0)
			e->line[e->pos++] = format[i];
		while (x++ < t - 1)
			e->line[e->pos++] = e->carac;
		if (e->t > 0 && e->t2 == 0)
			e->line[e->pos++] = format[i];
	}
	else if (e->point == 1)
		e->line[e->pos++] = format[i];
	return (-5);
}
