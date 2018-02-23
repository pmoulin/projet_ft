/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:32:05 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 16:07:05 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_o5(t_env *e, char *tmp3, int x)
{
	e->line = ft_strdup(tmp3);
	free(tmp3);
}

static void		flag_o4(char **tmp, char **tmp3, int i1, t_env *e)
{
	int		x;
	int		v;
	int		size;

	size = i1;
	x = 0;
	v = 0;
	i1 = 0;
	while (x < size && tmp[x] != NULL)
	{
		tmp3[0][v++] = tmp[x][i1++];
		(!tmp[x][i1]) ? x++ : 0;
		(!tmp[x - 1][i1]) ? i1 = 0 : 0;
		if (!tmp[x])
			break ;
	}
	ft_strrev(tmp3[0]);
	free_tab(tmp, x);
	free(tmp);
	if ((e->t != 0 || e->t2 != 0) && e->h_tag == 0)
	{
		choice_preci_and_lenght_for_oxdu(e, *tmp3);
		free(*tmp3);
	}
}

static int		flag_o3(unsigned long long int i1, char ***tmp, int v, t_env *e)
{
	unsigned long long int		i2;
	int							x;

	if (ft_strcmp(e->type_convert, "*") == 0 && e->o == 1)
		i1 = (unsigned int)i1;
	x = 0;
	while (i1 > 0)
	{
		i2 = i1;
		i1 = i1 / 8;
		i2 = i2 % 8;
		v++;
		tmp[0][x] = ft_ullitoa(i2);
		x++;
		if (i1 < 8 && i1 != 0)
		{
			tmp[0][x++] = ft_ullitoa(i1);
			tmp[0][x] = NULL;
			break ;
		}
	}
	return (x);
}

static int		flog_o2(t_env *e, unsigned long long int nb, int i, char type)
{
	char						**tmp;
	char						*tmp3;
	unsigned long long int		x1;
	unsigned long long int		i1;
	int							v;

	v = 0;
	i1 = nb;
	while ((unsigned long int)i1 > 8)
	{
		i1 = i1 / 8;
		v++;
	}
	if (!(tmp = (char **)malloc(sizeof(char *) * (v + 3))))
		ft_error("Malloc_ERROR", "flag_o one");
	x1 = flag_o3(nb, &tmp, v, e);
	(!(tmp3 = ft_strnew(x1))) ? ft_error("malloc ERROR", "FLAG_O Two") : 0;
	flag_o4(tmp, &tmp3, x1, e);
	(e->h_tag == 1) ? e->h_tag = h_tag(e, &tmp3, type) : 0;
	if ((e->t != 0 || e->t2 != 0) && e->h_tag != 0)
	{
		choice_preci_and_lenght_for_oxdu(e, tmp3);
		free(tmp3);
	}
	(e->t == 0 && e->t2 == 0) ? flag_o5(e, tmp3, 0) : 0;
}

int				flag_o(unsigned long long int nb, int i, t_env *e, char type)
{
	int							v;
	char						**tmp;

	v = 0;
	if (nb == 0 && e->t == 0 && e->t2 == 0 && e->h_tag == 0 && e->point == 1)
		return (i);
	if ((nb == 0 && e->t == 0 && e->t2 == 0 && e->h_tag == 1) || (nb == 0 &&
	e->t == 0 && e->t2 == 0 && e->h_tag == 0 && e->point == 0))
	{
		(!(e->line = ft_strnew(1))) ? ft_error("MALLOC_LINE", "FLAG_O") : 0;
		e->line[0] = '0';
		return (i);
	}
	else if (nb == 0 && (e->t != 0 || e->t2 != 0))
	{
		choice_preci_and_lenght_for_oxdu(e, "\0");
		return (i);
	}
	flog_o2(e, nb, i, type);
	return (i);
}
