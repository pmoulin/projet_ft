/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_for_oxdu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:44:16 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 17:38:50 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			alloc_tmp(char **tmp, int i)
{
	if (!(*tmp = (char *)malloc(sizeof(char) * (i + 1))))
		ft_error("FAIL malloc", "ALLOC_TMP");
	ft_bzero((char *)*tmp, i);
}

void			check_space_to_line(t_env *e, char *param)
{
	int		t;
	int		x;

	x = (param != NULL) ? (int)ft_strlen(param) : 0;
	t = e->t;
	if (e->t < 0)
		t = -e->t;
	if (e->t2 < t)
	{
		if (!(e->line = ft_strnew(x + t)))
			ft_error("MALLOC_LINE", "CHECK_SPACE_TO_LINE");
	}
	else if (t < e->t2)
	{
		if (!(e->line = ft_strnew(x + e->t2)))
			ft_error("MALLOC_LINE", "CHECK_SPACE_TO_LINE");
	}
}

static int		remp_tab_preci_2(t_env *e, char **tmp, int signe, char *param)
{
	int		i;
	int		x;
	int		v;

	v = 0;
	i = 0;
	x = 0;
	if (e->nega == 1 && e->carac == '0')
		tmp[0][i++] = '-';
	else if (e->plus == 1 && e->carac == '0')
		tmp[0][i++] = '+';
	while (i < e->t2 - (int)ft_strlen(param) + signe)
		tmp[0][i++] = e->carac;
	if (e->nega == 1 && e->carac == ' ')
		tmp[0][i++] = '-';
	else if (e->plus == 1 && e->carac == ' ')
		tmp[0][i++] = '+';
	if (param && e->t2 <= (int)ft_strlen(param))
		while (i < (int)ft_strlen(param) + signe)
			tmp[0][i++] = param[v++];
	else
		while (i < e->t2 + signe)
			tmp[0][i++] = param[v++];
	return (i);
}

static void		remp_tab_preci(char carac, char *param, char **tmp, t_env *e)
{
	int		i;
	int		v;
	int		signe;

	signe = 0;
	if (e->plus != 0 || e->nega != 0)
		signe = 1;
	v = 0;
	i = 0;
	if (e->t2 > 0)
	{
		e->carac = carac;
		i = remp_tab_preci_2(e, tmp, signe, param);
	}
	else if (e->t2 < 0 && e->tv[0] != 0)
	{
		if (e->nega == 1)
			tmp[0][i++] = '-';
		while (i < (int)ft_strlen(param))
			*tmp[i++] = param[v++];
		while (i < -e->t2 + (int)ft_strlen(param) + e->nega)
			*tmp[i++] = carac;
	}
	tmp[0][i] = '\0';
}

void			precision_for_oxdu(t_env *e, char *param, int v)
{
	int			i;
	char		*tmp;

	v = 0;
	i = 0;
	e->pos = 0;
	check_space_to_line(e, param);
	if (e->t2 < 0 && e->tv[1] != 0)
		alloc_tmp(&tmp, -e->t2 + (int)ft_strlen(param));
	else if (e->t2 > 0)
		alloc_tmp(&tmp, e->t2 + (int)ft_strlen(param));
	else
		return ;
	if (e->tv[1] != 0 || e->tv[0] != 0)
		if (e->point == 1 && e->t2 != 0 && e->tv[1] != 0)
			remp_tab_preci(e->carac, param, &tmp, e);
	while (tmp[i])
		e->line[e->pos++] = tmp[i++];
	free(tmp);
}
