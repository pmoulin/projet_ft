/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_for_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:09:18 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 17:38:05 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lenght_for_s_3(t_env *e, char *tmp, char *param, int i)
{
	int		t;

	t = (e->t < 0) ? -e->t : e->t;
	while (param[i])
		tmp[e->norme++] = param[i++];
	while (e->norme < t)
		tmp[e->norme++] = e->carac;
}

static void	lenght_for_s_2(t_env *e, char *tmp, char *param, int i)
{
	int		x;
	int		t;

	t = (e->t < 0) ? -e->t : e->t;
	x = (param != NULL) ? (int)ft_strlen(param) : 0;
	if (e->t > x && e->t > 0)
	{
		while (e->norme < e->t - x)
			tmp[e->norme++] = e->carac;
		while ((e->norme < e->t || e->norme < x) && param != 0 && e->point == 0)
			tmp[e->norme++] = param[i++];
	}
	else if (e->t < 0 && t > x)
		lenght_for_s_3(e, tmp, param, i);
	else if (e->t > 0 && e->t < x)
	{
		while (e->norme < e->t && e->point == 1)
			tmp[e->norme++] = e->carac;
		while (param[i] && e->point == 0)
			tmp[e->norme++] = param[i++];
	}
	tmp[e->norme] = '\0';
}

void		lenght_for_s(t_env *e, char *param)
{
	int		x;
	int		i;
	int		t;
	char	*tmp;

	t = 0;
	i = 0;
	e->norme = 0;
	x = (param != NULL) ? (int)ft_strlen(param) : 0;
	t = (e->t < 0) ? -e->t : e->t;
	if (x > t)
		alloc_tmp(&tmp, x);
	else if (x < t)
		alloc_tmp(&tmp, x + t);
	check_space_to_line(e, param);
	if (e->t > x && e->t2 == 0 && e->point == 1)
		while (e->norme < e->t)
			tmp[e->norme++] = e->carac;
	lenght_for_s_2(e, tmp, param, i);
	while (tmp[i])
		e->line[e->pos++] = tmp[i++];
	free(tmp);
}
