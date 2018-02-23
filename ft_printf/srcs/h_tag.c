/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_tag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 10:29:19 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/28 11:44:58 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		add_letter(int *x, char type, char *tmp2, t_env *e)
{
	int		i;

	i = 0;
	tmp2[*x] = '0';
	*x += 1;
	if (type == 'x')
	{
		tmp2[*x] = 'x';
		*x += 1;
	}
	else if (type == 'X')
	{
		tmp2[*x] = 'X';
		*x += 1;
	}
	if (e->carac == '0' && e->tv[1] == 0)
		return (2);
	return (0);
}

static int		tmp1_to_tmp2(char **tmp1, char *tmp2, int *i, t_env *e)
{
	int		x;

	x = 0;
	if (e->carac == ' ' && tmp1[0][0] == ' ')
	{
		while (tmp1[0][x] == ' ')
		{
			tmp2[x] = tmp1[0][*i];
			x += 1;
		}
		if (tmp1[0][x] != ' ' && tmp1[0][x] != '\0')
			x -= 2;
		*i = x + 2;
	}
	else
		x = 0;
	return (x);
}

int				h_tag(t_env *e, char **tmp1, char type)
{
	char	*tmp2;
	int		i;
	int		x;
	int		v;
	int		t;

	v = (type == 'c') ? 1 : 2;
	t = (e->t > 0) ? e->t : -e->t;
	i = 0;
	tmp2 = NULL;
	if (!(tmp2 = ft_strnew((int)ft_strlen(tmp1[0]) + 3)))
		ft_error("malloc_tmp2", "h_tag_x");
	if (e->t != 0)
		x = t - ((int)ft_strlen(tmp1[0])) - v;
	if ((e->carac == '0' || (e->t < 0 && e->carac == ' ')))
		x = 0;
	x = tmp1_to_tmp2(tmp1, tmp2, &i, e);
	i += add_letter(&x, type, tmp2, e);
	while (tmp1[0][i])
		tmp2[x++] = tmp1[0][i++];
	if (tmp1[0][0] != ' ' && e->carac == ' ' && e->x != 0)
		tmp2[x - 2] = '\0';
	ft_strdel(tmp1);
	tmp1[0] = tmp2;
	return (2);
}
