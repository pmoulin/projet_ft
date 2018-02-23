/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pointeur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:24:22 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 15:26:08 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_iteration(void *p, int v)
{
	unsigned long	adr;

	adr = (unsigned long)p;
	while (((adr / 16 > 0)))
	{
		adr /= 16;
		v++;
	}
	return (v);
}

static int		flag_p_crea_addr(void *p, int i, char res[12], int v)
{
	unsigned long	adr;
	char			*base;
	int				s;

	adr = (unsigned long)p;
	base = "0123456789abcdef";
	s = v;
	while (((adr / 16 > 0)))
	{
		res[v] = base[(adr % 16)];
		adr /= 16;
		v -= 1;
	}
	if (v == 13 && adr / 16 == 0)
		res[2] = base[(int)p];
	res[v] = base[(adr % 16)];
	res[s - v + 1] = '\0';
	v = 0;
	return (i + 1);
}

int				flag_p(void *p, int i, t_env *e)
{
	unsigned long	adr;
	int				v;
	char			res[15];
	int				i1;

	i1 = 0;
	v = 0;
	adr = (unsigned long)p;
	i = flag_p_crea_addr(p, i, res, count_iteration(p, v));
	if (e->t != 0 || e->t2 != 0)
		choice_preci_and_lenght_for_p(e, res);
	else
	{
		if (!(e->line = ft_strnew(16 + 1)))
			ft_error("MALLOC_LINE", "FLAG_P");
		e->line[i1++] = '0';
		e->line[i1++] = 'x';
		if (e->t == 0 && e->t2 == 0 && e->point == 0)
			while (res[v])
				e->line[i1++] = res[v++];
	}
	e->p = 0;
	return (i - 1);
}
