/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:07 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 16:08:51 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				s_nul(t_env *e, char **s, int choice, int i)
{
	if ((e->t == 0 && e->t2 == 0) || (choice == -1))
	{
		e->pos = 0;
		if (!(e->line = ft_strnew(6)))
			ft_error("malloc_line\n", "s_null");
		e->line[0] = '(';
		e->line[1] = 'n';
		e->line[2] = 'u';
		e->line[3] = 'l';
		e->line[4] = 'l';
		e->line[5] = ')';
		if (choice == -1)
			e->line[6] = '\0';
	}
	else
	{
		*s = ft_strnew(6);
		s[0][0] = '(';
		s[0][1] = 'n';
		s[0][2] = 'u';
		s[0][3] = 'l';
		s[0][4] = 'l';
		s[0][5] = ')';
	}
	return (i);
}

int				flag_s(char *s, int i1, t_env *e)
{
	int		v;
	int		i;

	i = 0;
	v = 0;
	if (!s)
		s_nul(e, &s, 0, i);
	if (e->t == 0 && e->t2 == 0 && s == NULL)
		return (i1);
	if (e->t == 0 && e->t2 == 0 && s != NULL)
	{
		if (!(e->line = ft_strnew((int)ft_strlen(s) + 1)))
			ft_error("malloc_line\n", "flag_d_i");
		while (s && s[v])
			e->line[i++] = s[v++];
		e->line[i] = '\0';
	}
	else if (e->t != 0 || e->t2 != 0)
	{
		choice_precision_and_lenght_for_s(e, s);
		if (ft_strcmp(s, "(null)") == 0)
			free(s);
	}
	e->s = 0;
	return (i1);
}

int				flag_c(char c, int i, t_env *e)
{
	int		t;
	int		i1;

	i1 = 0;
	t = (e->t < 0) ? -e->t : e->t;
	if (e->t == 0)
	{
		if (!(e->line = ft_strnew(2)))
			ft_error("MALLOC_LINE", "FLAG_C1");
		e->line[0] = c;
		if (c == '\0')
			e->zero = 1;
		return (i);
	}
	if (t != 0)
	{
		if (!(e->line = ft_strnew(t + 1)))
			ft_error("MALLOC_LINE", "FLAG_C2");
		precision_char(e, c);
	}
	return (i);
}
