/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:27:00 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 17:07:30 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			remp_tab_convert(t_env *e, char *type)
{
	if ((int)ft_strlen(type) == 1 && e->type_convert[0] == '*')
	{
		e->type_convert[0] = type[0];
		e->type_convert[1] = '\0';
		return (1);
	}
	else if ((int)ft_strlen(type) == 2 && e->type_convert[0] == '*')
	{
		e->type_convert[0] = type[0];
		e->type_convert[1] = type[1];
		e->type_convert[2] = '\0';
		return (1);
	}
	else if (e->type_convert[0] != '*')
	{
		e->type_convert[0] = '*';
		e->type_convert[1] = '\0';
		return (1);
	}
	return (0);
}

int			parse_point_h_tag(t_env *e, const char *restrict format, int i)
{
	if (format[i] == '#')
		e->h_tag = 1;
	else if (format[i] == '.')
		e->point = 1;
	return (i + 1);
}

static int	parse_signe_and_space(t_env *e, const char *restrict format, int i)
{
	int		i1;

	i1 = -1;
	if (format[i] == '+')
		e->plus = 1;
	else if (format[i] == ' ')
	{
		if (i1 = check_type(i + 1, format, e) != 0 || (format[i + 1] >= '0'
		&& format[i + 1] <= '9'))
			e->i = 3;
		i++;
		if (format[i] != ' ' && format[i] != '+' && format[i] != '-'
		&& (i1 = check_type(i, format, e)) == 0 && format[i] != '.'
		&& format[i] > 57 && format[i] != 48)
		{
			check_convert(e, format, i, 0);
			if (e->type_convert[0] == '*')
				return (-3);
		}
		else
			return (i);
	}
	return (i + 1);
}

static int	search_param_for_flag(t_env *e, const char *restrict s, int i,
int *i1)
{
	if (s[i] == ' ' || s[i] == '+')
		i = (parse_signe_and_space(e, s, i) > 0) ? i + 1 : -2;
	else if ((s[i] == '.' && e->point == 0) || (s[i] == '#' && e->h_tag == 0))
		i = parse_point_h_tag(e, s, i);
	else if ((s[i] <= '9' && s[i] >= '0') || (s[i] == '-' && s[i + 1] <= '9'
	&& s[i + 1] >= '0'))
		i = parse_preci_and_lenght(e, s, i, NULL);
	else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
	{
		*i1 = check_convert(e, s, i, -50);
		i = (*i1 >= 0) ? *i1 : i;
	}
	else if (s[i] == '-' && s[i + 1] != '%' && (s[i + 1] < 48 || s[i + 1] > 57))
	{
		e->n = 1;
		i++;
	}
	else if ((s[i] == '.' && e->point != 0) || (s[i] == '#' && e->h_tag != 0))
		i++;
	else if (i != -2 && e->tv[0] == 0 && e->tv[1] == 0 && s[i] != '\0'
	&& s[i] != '%' && check_param_valid(e, s, i) == 0)
		return (-2);
	return (i);
}

int			parse_string(const char *restrict format, va_list *ap,
	t_env *e, int i)
{
	int		i1;

	i1 = 0;
	init_param3(e);
	i++;
	while (format[i] && (i1 = check_type(i, format, e)) == 0 && i1 != -1
	&& i1 != -2)
	{
		if ((i = search_param_for_flag(e, format, i, &i1)) == -2)
			return (-2);
		if (format[i] == '%' || i1 == -5)
			break ;
		(format[i] == '\0') ? i1 = -1 : 0;
	}
	(format[i] == '\0' && e->t > 0 && e->n == 1) ? e->t = -e->t : 0;
	if (i1 != -1)
	{
		if (e->type_convert[0] != '*' && format[i] != 'p')
			i = parse_param_conv(e, ap, format, i);
		else
			i = choice_flag(i, e, ap, format);
		if (e->line)
			ft_putstr_like(e, 0);
	}
	return (i);
}
