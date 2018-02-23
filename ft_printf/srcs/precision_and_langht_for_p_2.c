/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_and_langht_for_p_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:58:26 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 17:37:08 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	remp_tab_lenght_2(t_env *e, char *param, char **tmp, char carac)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	if (e->carac == ' ' && (e->nega == 1 || e->plus == 1))
		tmp[0][i++] = '-';
	tmp[0][i++] = '0';
	tmp[0][i++] = 'x';
	if (e->t < 0 && e->carac == '0')
		e->carac = ' ';
	while (param[v])
		tmp[0][i++] = param[v++];
	while (i < e->t || i < -e->t)
		tmp[0][i++] = carac;
}

static void	remp_tab_lenght(char carac, char *param, char **tmp, t_env *e)
{
	int		i;
	int		v;

	v = 0;
	i = 0;
	if (e->t > 0 && (e->p == 0) || (e->p == 1 && e->carac == ' ' && e->t > 0))
	{
		if (e->carac == '0' && e->plus == 1 && e->n == 0)
			tmp[0][i++] = '+';
		if (ft_atoi(param) == 0 && ft_strlen(param) == 1)
			v = 0;
		else
			v = (int)ft_strlen(param);
		v = (e->p == 1) ? (int)ft_strlen(param) : v;
		while (i < e->t - v - 2)
			tmp[0][i++] = carac;
		tmp[0][i++] = '0';
		tmp[0][i++] = 'x';
		while ((i < e->t || i < (int)ft_strlen(param) + e->plus) &&
			e->tv[1] == 0 && e->t2 == 0 && (ft_atoi(param) != 0 || e->p == 1 ||
			ft_strlen(param) != 0))
			tmp[0][i++] = param[e->t2++];
	}
	else if ((e->t < 0 && e->tv[0] != 0) || e->p == 1)
		remp_tab_lenght_2(e, param, tmp, carac);
}

static void	remp_tab_preci(char carac, char *param, char **tmp, t_env *e)
{
	int		v;

	v = 0;
	e->s = 0;
	if (e->t2 > 0)
	{
		(e->nega == 1 && carac == '0') ? tmp[0][e->s++] = '-' : 0;
		tmp[0][e->s++] = '0';
		tmp[0][e->s++] = 'x';
		while (param[v] && e->s < e->t2)
			tmp[0][e->s++] = param[v++];
		while (e->s < e->t2 + 2)
			tmp[0][e->s++] = carac;
		(e->nega == 1 && carac == ' ') ? tmp[0][e->s++] = '-' : 0;
	}
	else if (e->t2 < 0 && e->tv[0] != 0)
	{
		(e->nega == 1) ? tmp[0][e->s++] = '-' : 0;
		while (e->s < (int)ft_strlen(param))
			*tmp[e->s++] = param[v++];
		while (e->s < -e->t2 + (int)ft_strlen(param) + e->nega)
			*tmp[e->s++] = carac;
	}
	tmp[0][e->s] = '\0';
}

void		preci_for_p(t_env *e, char *param, int v)
{
	char		*tmp;

	v = 0;
	e->pos = 0;
	if (e->line)
		free(e->line);
	check_space_to_line(e, param);
	if (e->t2 < 0 && e->tv[1] != 0)
		alloc_tmp(&tmp, -e->t2 + (int)ft_strlen(param));
	else if (e->t2 > 0)
		alloc_tmp(&tmp, e->t2 + (int)ft_strlen(param));
	else
		return ;
	if (e->tv[1] != 0 || e->tv[0] != 0)
	{
		if (e->point == 1 && e->t2 != 0 && e->tv[1] != 0)
			remp_tab_preci(e->carac, param, &tmp, e);
		else if (e->point == 0)
			remp_tab_lenght(e->carac, param, &tmp, e);
	}
	while (tmp[v] && e->h_tag == 0)
		e->line[e->pos++] = tmp[v++];
	e->line[e->pos] = '\0';
	free(tmp);
}

void		lenght_for_p(t_env *e, char *param, int v)
{
	int			i;
	char		*tmp;

	v = 0;
	i = 0;
	check_space_to_line(e, param);
	if (e->t < 0 && e->tv[0] != 0)
		alloc_tmp(&tmp, -e->t + ft_strlen(param));
	else if (e->t > 0)
		alloc_tmp(&tmp, e->t + ft_strlen(param));
	else
		return ;
	if (e->tv[0] != 0)
		remp_tab_lenght(e->carac, param, &tmp, e);
	(e->pos != 0) ? e->line[0] = ' ' : 0;
	v = e->pos;
	e->pos = (e->pos == 0) ? 0 : e->pos;
	while (i < ft_strlen(tmp) - v && e->h_tag == 0)
		e->line[e->pos++] = tmp[i++];
	e->line[e->pos] = '\0';
	free(tmp);
}
