/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:38:06 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 11:44:12 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cmp_conv_2(const char *restrict format, int i)
{
	int		y;

	y = 0;
	if (format[i] == 'h' && format[i + 1] != 'h')
		y = 2;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		y = 1;
	else if (format[i] == 'l' && format[i + 1] != 'l')
		y = 3;
	else if (format[i] == 'l' && format[i + 1] == 'l')
		y = 4;
	else if (format[i] == 'z')
		y = 5;
	else if (format[i] == 'j')
		y = 6;
	else
		return (0);
	return (y);
}

static int	cmp_conv(t_env *e, const char *restrict format, int i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (ft_strcmp(e->type_convert, "h") == 0)
		x = 2;
	else if (ft_strcmp(e->type_convert, "hh") == 0)
		x = 1;
	else if (ft_strcmp(e->type_convert, "l") == 0)
		x = 3;
	else if (ft_strcmp(e->type_convert, "ll") == 0)
		x = 4;
	else if (ft_strcmp(e->type_convert, "z") == 0)
		x = 5;
	else if (ft_strcmp(e->type_convert, "j") == 0)
		x = 6;
	y = cmp_conv_2(format, i);
	if (x < y && format[i + 1] != '%' && format[i + 1] != '\0')
		return (1);
	else if (format[i] != 'l' && format[i] != 'h' && format[i] != 'j'
		&& format[i] != 'z')
		return (1);
	else
		return (0);
}

static int	search_param_convert(t_env *e, int i, const char *restrict format)
{
	int	x;

	x = 0;
	if (format[i] == 'h' && format[i + 1] != 'h')
		x = remp_tab_convert(e, "h\0");
	else if (format[i] == 'h' && format[i + 1] == 'h')
		x = remp_tab_convert(e, "hh\0");
	else if (format[i] == 'l' && format[i + 1] != 'l')
		x = remp_tab_convert(e, "l\0");
	else if (format[i] == 'l' && format[i + 1] == 'l')
		x = remp_tab_convert(e, "ll\0");
	else if (format[i] == 'j')
		x = remp_tab_convert(e, "j\0");
	else if (format[i] == 'z')
		x = remp_tab_convert(e, "j\0");
	else
		return (0);
	return (x);
}

int			check_convert(t_env *e, const char *restrict format, int i, int *i1)
{
	int			x;
	char		c;

	x = 0;
	c = e->type_convert[0];
	if (e->type_convert[0] != '*')
		x = cmp_conv(e, format, i);
	else
		x = 1;
	if (x == 1)
	{
		if ((x = search_param_convert(e, i, format)) == 0)
		{
			if ((x = check_param_valid(e, format, i)) == 0)
				return (printf_faill_param(e, format, i, i1));
			else if (x == 1)
				return (i + 1);
			else
				return (-2);
		}
	}
	if (e->type_convert[0] == c)
		return (i + 1);
	return (i + (int)ft_strlen(e->type_convert));
}

int			parse_param_conv(t_env *e, va_list *ap, const char *restrict format,
int i)
{
	if (format[i] == 'c' || format[i] == 'C' || format[i] == 'S'
	|| format[i] == 's')
		i = choice_flag(i, e, ap, format);
	else
		i = choice_param_unsigned(ap, e, format, i);
	return (i);
}
