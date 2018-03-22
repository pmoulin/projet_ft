/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_and_lenght_for_oxdu.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:29:55 by phmoulin          #+#    #+#             */
/*   Updated: 2018/03/10 15:34:59 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	preci_and_lenght_for_oxdu_3(t_env *e, char *tmp, char *param, int x)
{
	int		i;
	int		t2;
	int		t;
	int		i1;

	i1 = 0;
	t = (e->t < 0) ? -e->t : e->t;
	t2 = (e->t2 < 0) ? -e->t2 : e->t2;
	i = 0;
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
	return (i);
}

static void	preci_and_lenght_for_oxdu_2(t_env *e, int i, char *tmp, char *param)
{
	int		i1;
	int		x;

	x = (int)ft_strlen(param);
	i1 = 0;
	if (e->nega == 1)
		tmp[i++] = '-';
	else if (e->plus == 1 && e->nega == 1)
		tmp[i++] = '+';
	while (i < e->t2 - (x - e->nega))
		tmp[i++] = '0';
	while (param[i1])
		tmp[i++] = param[i1++];
}

void		precision_and_lenght_for_oxdu(t_env *e, char *param, int i)
{
	int		x;
	char	*tmp;
	int		t;

	tmp = NULL;
	i = (i != 0) ? 0 : 0;
	t = (e->t < 0) ? -e->t : e->t;
	x = (int)ft_strlen(param);
	check_space_to_line(e, param);
	if (t > e->t2)
		alloc_tmp(&tmp, t + x);
	else if (e->t2 >= t)
		alloc_tmp(&tmp, e->t2 + x);
	if (e->t2 > t && e->h_tag != 1)
		preci_and_lenght_for_oxdu_2(e, i, tmp, param);
	else if (e->t < 0 && t > e->t2)
		preci_and_lenght_for_oxdu_3(e, tmp, param, x);
	else if (e->t2 > x || t >= e->t2)
		preci_and_lenght_for_oxdu_4(e, param, tmp, x);
	while (tmp[i])
	{
		e->line[e->pos++] = tmp[i++];
		e->line[e->pos] = '\0';
	}
	free(tmp);
}
