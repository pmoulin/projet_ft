/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:45:28 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 17:32:45 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	precision_and_lenght_for_s_2(t_env *e, char *p, char *tmp, int i)
{
	int		x;

	x = ((int)ft_strlen(p) == 0) ? 6 : (int)ft_strlen(p);
	if (e->t2 < x && e->t2 >= 0)
	{
		while ((i < e->t - e->t2 && p[0] != '\0') || (i < e->t && p[0] == '\0'))
			tmp[i++] = e->carac;
		while (i < e->t && p[e->norme])
			tmp[i++] = p[e->norme++];
	}
	else if (e->t2 < 0)
		while (i < -e->t2)
			tmp[i++] = ' ';
	else if (e->t2 > 0 && e->t2 > x)
	{
		x = (e->s == 2) ? 0 : x - 1;
		while (i <= e->t - e->t2 + x)
			tmp[i++] = e->carac;
		while (i < e->t + x)
			tmp[i++] = p[e->norme++];
	}
	else
		while (i < e->t && (i < e->t2 || i < -e->t2))
			tmp[i++] = e->carac;
	return (i);
}

static void	precision_and_lenght_s_3(t_env *e, char *param, char *tmp, int x)
{
	int		i;
	int		t;

	t = (e->t < 0) ? -e->t : e->t;
	i = 0;
	e->norme = 0;
	if (e->t > x)
	{
		while (i < t - x)
			tmp[i++] = ' ';
		while (i < e->t && param != NULL)
			tmp[i++] = param[e->norme++];
	}
	else if (e->t < x)
	{
		while (param[i] && i < e->t2 && param != NULL)
			e->line[e->pos++] = param[i++];
		while (e->pos < t)
			e->line[e->pos++] = e->carac;
	}
}

void		precision_and_lenght_for_s(t_env *e, char *param, int v)
{
	int		x;
	int		i;
	int		t;
	char	*tmp;

	e->pos = 0;
	i = 0;
	x = ((int)ft_strlen(param) == 0) ? 6 : (int)ft_strlen(param);
	t = (e->t < 0) ? -e->t : e->t;
	if (x > e->t2)
		alloc_tmp(&tmp, x);
	else if (t > e->t2 || x != 0)
		alloc_tmp(&tmp, t + 1);
	check_space_to_line(e, param);
	if (e->t > e->t2)
		tmp[precision_and_lenght_for_s_2(e, param, tmp, i)] = '\0';
	else if (e->t2 > e->t && e->t != x)
		precision_and_lenght_s_3(e, param, tmp, x);
	if (tmp != NULL)
	{
		while (tmp[i])
			e->line[e->pos++] = tmp[i++];
		e->line[e->pos] = '\0';
	}
	free(tmp);
}

void		precision_for_s(t_env *e, char *param, int v)
{
	int		x;
	int		i;
	char	*tmp;

	e->pos = 0;
	i = 0;
	x = (param != NULL) ? (int)ft_strlen(param) : 0;
	tmp = NULL;
	if (x > e->t2)
		alloc_tmp(&tmp, x);
	else if (x < e->t2)
		alloc_tmp(&tmp, x + e->t2);
	check_space_to_line(e, param);
	if (e->t2 >= x)
		while (param[i] && param != NULL)
			e->line[e->pos++] = param[i++];
	else if (e->t2 < x && e->t2 != 0)
		while (i < e->t2 && param != NULL)
			e->line[e->pos++] = param[i++];
	free(tmp);
}

void		precision_char(t_env *e, char param)
{
	int		i;

	e->pos = 0;
	i = 0;
	if (e->t != 0 && e->t > 1)
	{
		while (i++ < e->t - 1)
			e->line[e->pos++] = e->carac;
		if (param != '\0')
			e->line[e->pos++] = param;
		else
			e->zero = e->pos;
	}
	else if (e->t != 0 && e->t < 1)
	{
		if (param != '\0')
			e->line[e->pos++] = param;
		else
			e->zero = e->pos++;
		e->line[e->pos] = '\0';
		while (i++ < -e->t - 1)
			e->line[e->pos++] = e->carac;
	}
}
