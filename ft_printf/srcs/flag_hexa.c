/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:59:28 by phmoulin          #+#    #+#             */
/*   Updated: 2018/03/10 16:57:38 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_x4(t_env *e, char **tmp3, int x, char type)
{
	x = 0;
	e->pos = 0;
	if (e->h_tag == 1)
	{
		if (e->line && (e->tv[0] != 0 || e->tv[1] != 0))
		{
			free(*tmp3);
			*tmp3 = ft_strdup(e->line);
			ft_strdel(&e->line);
		}
		h_tag(e, tmp3, type);
	}
	if (e->h_tag == 1 || (e->tv[0] == 0 && e->tv[1] == 0))
		e->line = ft_strdup(*tmp3);
	ft_strdel(tmp3);
}

static void		flag_x3(t_env *e, char ***tmp, char **tmp3, int x)
{
	int		v;
	int		i1;
	int		x1;

	v = 0;
	i1 = 0;
	x1 = 0;
	while (tmp[0][x1] && x1 < x)
	{
		if (tmp[0][x1][i1] != '\0')
		{
			tmp3[0][v] = tmp[0][x1][i1];
			v++;
		}
		i1 = (tmp[0][x1][i1 + 1] != '\0') ? i1 + 1 : 0;
		if (i1 == 0)
			x1++;
	}
	ft_strrev(tmp3[0]);
	if (e->tv[0] != 0 || e->tv[1] != 0)
		choice_preci_and_lenght_for_oxdu(e, *tmp3);
	free_tab(tmp[0], x1);
	free(tmp[0]);
}

static int		flag_x2(char type, int v, unsigned long long int i1,
char ***tmp)
{
	char						*tmp2;
	unsigned long long int		i2;
	int							x;

	tmp2 = NULL;
	x = 0;
	i2 = i1;
	while (i1 > 16)
	{
		i2 = i1 % 16;
		i1 = i1 / 16;
		tmp2 = conv_nb_to_letter((int *)&i2, type);
		if (v-- == 1)
		{
			tmp[0][x++] = ft_strdup(tmp2);
			ft_strdel(&tmp2);
			tmp[0][x++] = (i1 <= 16) ? conv_nb_to_letter((int *)&i1, type) : 0;
			tmp[0][x++] = (i1 == 16) ? ft_strdup("01\0") : NULL;
			break ;
		}
		tmp[0][x++] = ft_strdup(tmp2);
		ft_strdel(&tmp2);
	}
	(tmp2 != NULL) ? free(tmp2) : 0;
	return (x);
}

static void		flag_x_2(t_env *e, char *tmp3, char type,
unsigned long long int nb)
{
	int						v;
	int						x;
	unsigned long long int	i1;
	char					**tmp;

	(nb > 1) ? tmp3 = NULL : 0;
	v = 0;
	x = 0;
	i1 = nb;
	while (i1 > 16)
	{
		i1 = i1 / 16;
		v++;
	}
	i1 = nb;
	if (!(tmp = (char **)malloc(sizeof(char *) * (v + 3))))
		ft_error("ERROR MALLOC", "FLAG_X");
	tmp[v + 2] = NULL;
	if (tmp3 == NULL)
		x = flag_x2(type, v, i1, &tmp);
	if (x > 0)
		tmp3 = ft_strnew(x + 2);
	e->type = type;
	flag_x3(e, &tmp, &tmp3, x);
	flag_x4(e, &tmp3, x, type);
}

int				flag_x(unsigned long long int nb, int i, t_env *e, char type)
{
	char					*tmp3;

	if (nb == 1 && (e->tv[0] != 0 || e->tv[1] != 0))
	{
		if (!(tmp3 = ft_strnew(1)))
			ft_error("MALLOC TMsP3", "x1");
		tmp3[0] = '1';
	}
	else if ((nb == 0 || nb == 1) && e->t == 0 && e->t2 == 0)
		return (nb_zero_or_one(e, i, nb));
	if (nb > 0)
		flag_x_2(e, tmp3, type, nb);
	else if (nb == 0)
	{
		if (!(e->line = ft_strnew(e->t + 1)))
			ft_error("MALOC LINE", "FLAG_X");
		if (e->x == 0 && e->h_tag == 0 && e->point == 0)
			e->line[e->pos++] = '0';
		while (e->t-- > 0)
			e->line[e->pos++] = e->carac;
		if (nb == 0 && e->h_tag == 1 && e->point == 0)
			e->line[e->pos++] = '0';
	}
	e->x = 0;
	return (i);
}
