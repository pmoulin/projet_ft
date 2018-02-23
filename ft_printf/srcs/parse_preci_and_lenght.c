/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_preci_and_lenght.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:54:07 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 16:35:11 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_lengh(t_env *e, const char *restrict format, int i, char *tmp)
{
	if (format[i] == '0' && (format[i + 1] == '+' || format[i + 1] == '-')
	&& format[i + 2] <= '9' && format[i + 2] >= '0')
	{
		e->carac = '0';
		if (format[i + 1] == '+')
			e->plus = 1;
		else if (format[i + 1] == '-')
		{
			e->n = 1;
			e->carac = ' ';
		}
		i += 2;
	}
	else if (format[i] == 48 && format[i + 1] <= 57 && format[i + 1] >= 48)
		e->carac = 48;
	else
		e->carac = ' ';
	e->n = (format[i] == '-') ? 1 : e->n;
	e->plus = (format[i] == '+') ? 1 : e->plus;
	e->tv[0] = 1;
	e->t = ft_atoi((char *)&format[i]);
	tmp = ft_itoa(e->t);
	free(tmp);
	i += ft_strlen(tmp);
	return (i);
}

static int	parse_preci(t_env *e, const char *restrict format, int i, char *tmp)
{
	e->tv[1] = 1;
	e->t2 = ft_atoi((char *)&format[i]);
	if (e->t == 0 || e->carac == '0')
		e->carac = '0';
	else if (e->point == 1 && e->t2 > 0)
		e->carac = ' ';
	else if (e->t2 < 0)
		e->carac = ' ';
	tmp = ft_itoa(e->t2);
	free(tmp);
	i += ft_strlen(tmp);
	return (i);
}

int			parse_preci_and_lenght(t_env *e, const char *restrict format,
int i, char *tmp)
{
	if (e->point == 0 && e->t == 0)
	{
		i = parse_lengh(e, format, i, tmp);
		if (format[i] >= '0' && format[i] <= '9')
			i++;
		if (tmp != NULL)
			free(tmp);
		return (i);
	}
	else if ((e->point == 1 || e->h_tag == 1) && e->tv[1] == 0)
	{
		i = parse_preci(e, format, i, tmp);
		if (tmp != NULL)
			free(tmp);
		return (i);
	}
	return (i + 1);
}
