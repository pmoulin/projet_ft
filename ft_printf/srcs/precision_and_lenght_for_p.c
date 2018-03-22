/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_and_lenght_for_p.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:02:37 by phmoulin          #+#    #+#             */
/*   Updated: 2018/03/10 15:32:08 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lenght_and_preci_for_p_2(t_env *e, char *tmp, char *param, int x)
{
	int		i;
	int		i1;

	i1 = 0;
	i = 0;
	tmp[i++] = '0';
	tmp[i++] = 'x';
	while (i <= e->t2 - (x) + 1)
		tmp[i++] = '0';
	while (param[i1])
		tmp[i++] = param[i1++];
}

static void	lenght_and_preci_for_p_3(t_env *e, char *tmp, char *param, int x)
{
	int		i;
	int		t;
	int		t2;
	int		i1;

	i1 = 0;
	i = 0;
	t2 = (e->t2 < 0) ? -e->t2 : e->t2;
	t = (e->t < 0) ? -e->t : e->t;
	if (e->n == 1 && e->nega == 1)
		tmp[i++] = '-';
	else if (e->plus == 1)
		tmp[i++] = '+';
	if (t2 > x && e->t2 > 0 && e->t < 0)
		while (i < t2 - x + e->plus)
			tmp[i++] = '0';
	while (param[i1])
		tmp[i++] = param[i1++];
	if (x < t && e->t < 0 && e->t2 > 0)
		while (i < t || i < t2)
			tmp[i++] = ' ';
	else if (e->t2 < 0)
		while (i < t2)
			tmp[i++] = ' ';
}

static int	lenght_and_preci_for_p_4(t_env *e, char *tmp, int x)
{
	int		i;
	int		t;

	t = (e->t < 0) ? -e->t : e->t;
	i = 0;
	if (t > e->t2)
		while (i < (t - (x + 2)) - e->plus)
			tmp[i++] = ' ';
	tmp[i++] = '0';
	tmp[i++] = 'x';
	if (e->t2 > x)
		i = (e->plus == 1) ? t - e->t2 - e->plus : t - e->t2 - e->n;
	if (e->n == 1 && e->nega == 1)
	{
		(t > x && e->t2 < x) ? i -= 1 : 0;
		tmp[i++] = (e->t2 > x) ? '-' : '-';
	}
	if (e->t2 > x)
	{
		(e->n == 1 && e->nega == 1) ? tmp[i++] = '-' : 0;
		(e->plus == 1) ? tmp[i++] = '+' : 0;
		while (e->norme++ < e->t2 - x)
			tmp[i++] = '0';
	}
	return (i);
}

static void	alloc_space(t_env *e, char *param, char **tmp)
{
	int		t;

	t = (e->t < 0) ? -e->t : e->t;
	check_space_to_line(e, param);
	if (t > e->t2)
		alloc_tmp(tmp, t + (int)ft_strlen(param));
	else if (e->t2 >= t)
		alloc_tmp(tmp, e->t2 + (int)ft_strlen(param));
}

void		lenght_and_preci_for_p_1(t_env *e, char *param, int v)
{
	int		i;
	char	*tmp;
	int		t;

	i = (v != 0) ? 0 : 0;
	t = (e->t < 0) ? -e->t : e->t;
	alloc_space(e, param, &tmp);
	if (e->t2 > t && e->h_tag != 1)
		lenght_and_preci_for_p_2(e, tmp, param, (int)ft_strlen(param));
	else if (e->t < 0 && t > e->t2)
		lenght_and_preci_for_p_3(e, tmp, param, (int)ft_strlen(param));
	else if (e->t2 > (int)ft_strlen(param) || t >= e->t2)
	{
		i = lenght_and_preci_for_p_4(e, tmp, (int)ft_strlen(param));
		t = 0;
		while (param[t])
			tmp[i++] = param[t++];
	}
	i = 0;
	while (tmp[i] && e->h_tag == 0)
	{
		e->line[e->pos++] = tmp[i++];
		e->line[e->pos] = '\0';
	}
	free(tmp);
}
