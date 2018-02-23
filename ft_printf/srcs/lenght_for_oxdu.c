/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_for_oxdu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:22:08 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 17:37:26 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		remp_tab_lenght_4(t_env *e, char *param, char **tmp, int i)
{
	int		v;

	v = 0;
	if (e->carac == ' ' && e->nega == 1)
		tmp[0][i++] = '-';
	else if (e->plus == 1 && e->nega == 0)
		tmp[0][i++] = '+';
	if (e->t < 0 && e->carac == '0')
		e->carac = ' ';
	if (e->h_tag == 1 && e->o != 0)
		tmp[0][i++] = '0';
	while (param[v] && i < (int)ft_strlen(param) + e->n)
		tmp[0][i++] = param[v++];
	while (i < e->t || i < -e->t)
		tmp[0][i++] = e->carac;
}

static void		remp_tab_lenght_3(t_env *e, char *param, char **tmp, char carac)
{
	int	i;

	i = 0;
	if ((e->carac == '0' || e->n == 1) && e->nega == 1)
		i++;
	else if ((e->carac == '0' || e->n == 1) && e->plus == 1 && e->nega == 0)
		i++;
	e->n = 0;
	while (param[e->n])
		tmp[0][i++] = param[e->n++];
	while (i < e->t)
		tmp[0][i++] = carac;
	e->n = 1;
}

static int		remp_tab_lenght_2(t_env *e, char *param, char **tmp, int i)
{
	int		v;

	v = e->s;
	e->s = 0;
	if (e->n == 0)
		while (i < e->t - v)
			tmp[0][i++] = e->carac;
	else if (e->n == 1)
		remp_tab_lenght_3(e, param, tmp, e->carac);
	if (e->nega == 1 && e->carac == ' ' && e->n == 0)
		tmp[0][i - 1] = '-';
	else if (e->carac == ' ' && e->n == 0 && e->plus == 1 && e->nega == 0)
		tmp[0][i - 1] = '+';
	if (e->h_tag == 1 && e->o != 0 && e->n == 0)
		tmp[0][i - 1] = '0';
	return (i);
}

static void		remp_tab_lenght(char carac, char *para, char **tmp, t_env *e)
{
	int		i;
	int		v;

	i = 0;
	if (e->tv[1] != 0)
		carac = ' ';
	if (e->t > 0 && ((e->p == 0) || (e->p == 1 && e->carac == ' ' && e->t > 0)))
	{
		if ((e->carac == '0' || e->n == 1) && e->nega == 1)
			tmp[0][i++] = '-';
		else if ((e->carac == '0' || e->n == 1) && e->plus == 1 && e->nega == 0)
			tmp[0][i++] = '+';
		v = (ft_atoi(para) == 0 && ft_strlen(para) == 1) ? 0 : ft_strlen(para);
		v = (e->p == 1) ? (int)ft_strlen(para) : v;
		e->carac = carac;
		e->s = v;
		i = remp_tab_lenght_2(e, para, tmp, i);
		v = 0;
		while ((i < e->t || i < (int)ft_strlen(para) + e->plus) &&
			e->tv[1] == 0 && e->t2 == 0 && e->n == 0 &&
			(ft_atoi(para) != 0 || e->p == 1 || ft_strlen(para) != 0))
			tmp[0][i++] = para[v++];
	}
	else if ((e->t < 0 && e->tv[0] != 0) || e->p == 1)
		remp_tab_lenght_4(e, para, tmp, i);
}

void			lenght_for_oxdu(t_env *e, char *param, int v)
{
	int			i;
	char		*tmp;

	v = 0;
	i = 0;
	tmp = NULL;
	check_space_to_line(e, param);
	if (e->t < 0 && e->tv[0] != 0)
		alloc_tmp(&tmp, -e->t + ft_strlen(param));
	else if (e->t > 0)
		alloc_tmp(&tmp, e->t + ft_strlen(param));
	else
		return ;
	remp_tab_lenght(e->carac, param, &tmp, e);
	if (e->pos != 0)
		e->line[0] = ' ';
	v = e->pos;
	e->pos = (e->pos == 0) ? 0 : e->pos;
	while (i < ft_strlen(tmp) - v)
	{
		e->line[e->pos++] = tmp[i++];
		e->line[e->pos] = '\0';
	}
	free(tmp);
}
