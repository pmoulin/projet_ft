/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:27:22 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/30 19:43:14 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_space_first_carac(t_env *e, char *tmp, char *size)
{
	int		i1;
	int		i2;

	i2 = 0;
	i1 = 0;
	if (e->t == 0 && e->t2 == 0)
	{
		if (e->line != NULL)
			ft_strdel(&e->line);
		e->line = ft_strdup(size);
	}
	else
		i2++;
	tmp = ft_strnew(ft_strlen(e->line) + 1);
	tmp[i1++] = ' ';
	while (e->line[i2])
		tmp[i1++] = e->line[i2++];
	free(e->line);
	e->line = NULL;
	e->line = ft_strdup(tmp);
	if (tmp != NULL)
		free(tmp);
}

static void		modif_content_size(int nb, t_env *e, char **size)
{
	int		i;
	int		v;
	char	*tmp;

	i = 0;
	v = 0;
	tmp = NULL;
	if (!(tmp = ft_strnew((int)ft_strlen(size[0]))))
		ft_error("MALLOC_LINE", "MODIF content_size FLAG1");
	while (size[0][i])
	{
		if (size[0][i] == '-')
		{
			i++;
			e->nega = 1;
		}
		tmp[v] = size[0][i];
		i++;
		v++;
	}
	if (v != 0)
		free(size[0]);
	size[0] = ft_strdup(tmp);
	free(tmp);
}

static void		remp_line(t_env *e, long long int nb, char *size, int v)
{
	(e->plus == 1 && nb >= 0) ? e->line[e->pos++] = '+' : 0;
	while (size[v])
		e->line[e->pos++] = size[v++];
}

int				flag_d_i(int i1, long long int nb, t_env *e, int v)
{
	char	*size;

	(e->type_convert[0] != '*') ? nb = (long long int)nb : 0;
	if (e->type_convert[0] == '*' && e->i == 1)
		size = ft_itoa((int)nb);
	else
		size = ft_llitoa((long long int)nb);
	if (e->t == 0 && e->t2 == 0)
		if (!(e->line = ft_strnew((int)ft_strlen(size) + 1 + e->plus)))
			ft_error("MALLOC_LINE", "FLAG D_I");
	(nb < 0) ? e->nega = 1 : 0;
	if ((e->plus == 1 || nb < 0) && (e->t != 0 || e->t2 != 0))
		modif_content_size(nb, e, &size);
	if ((e->tv[0] != 0 || e->tv[1] != 0) && (e->t != 0 || e->t2 != 0))
		choice_preci_and_lenght_for_oxdu(e, size);
	if (e->i == 3 && e->plus == 0 && e->nega == 0 && nb >= 0 && e->line != NULL
	&& (e->carac != ' ' || (e->t == 0 && e->t2 == 0)))
		add_space_first_carac(e, NULL, size);
	else if (e->line[0] == '\0' && ((e->t == 0 && e->t2 == 0 && e->point == 0)
	|| (e->tv[1] != 0 && nb != 0) || (e->point == 1 && nb != 0)))
		remp_line(e, nb, size, v);
	free(size);
	return (i1);
}
