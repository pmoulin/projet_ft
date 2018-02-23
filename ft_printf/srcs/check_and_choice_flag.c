/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_choice_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:23:39 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 11:56:58 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_param_valid(t_env *e, const char *restrict format, int i)
{
	int		x;

	x = 0;
	if (format[i] == '.')
		i++;
	if (format[i] == 'i' || format[i] == 'd' || format[i] == 'D' ||
	format[i] == 'f' || format[i] == 'c' || format[i] == 'C' || format[i] == 's'
	|| format[i] == 'S' || format[i] == 'p' || format[i] == 'x' ||
	format[i] == 'X' || format[i] == 'u' || format[i] == 'U' || format[i] == 'o'
	|| format[i] == 'O' || format[i] == '%')
		x = 1;
	else if ((format[i] >= 'a' && format[i] <= 'z' || format[i] >= 'A'
	&& format[i] <= 'Z'))
		return (0);
	i++;
	return (x);
}

int			check_pos(const char *restrict format, int i, int x)
{
	while (x++ == 0)
	{
		if (format[i] == '.')
			i++;
		if (format[i] == 'i' || format[i] == 'd' || format[i] == 'D')
			break ;
		else if (format[i] == 'f')
			break ;
		else if (format[i] == 'c' || format[i] == 'C')
			break ;
		else if (format[i] == 's')
			break ;
		else if (format[i] == 'p')
			break ;
		else if (format[i] == 'x' || format[i] == 'X')
			break ;
		else if (format[i] == 'u' || format[i] == 'U')
			break ;
		else if (format[i] == 'o' || format[i] == 'O')
			break ;
		else if (format[i] == '%')
			break ;
		i++;
	}
	return (i);
}

int			check_type(int i, const char *restrict format, t_env *e)
{
	if (format[i] == 'i' || format[i] == 'd')
		e->i = (e->i >= 2) ? 3 : 1;
	else if (format[i] == 'D')
		e->i = 2;
	else if (format[i] == 'f')
		e->f = 1;
	else if (format[i] == 'c' || format[i] == 'C')
		e->c = 1;
	else if (format[i] == 's' || format[i] == 'S')
		e->s = (format[i] == 's') ? 1 : 2;
	else if (format[i] == 'p')
		e->p = 1;
	else if (format[i] == 'x' || format[i] == 'X')
		e->x = 1;
	else if (format[i] == 'u')
		e->u = 1;
	else if (format[i] == 'U')
		e->u = 2;
	else if (format[i] == 'o' || format[i] == 'O')
		e->o = (format[i] == 'o') ? 1 : 2;
	else if (format[i] == '%')
		e->modulo = 1;
	else
		return (0);
	return (i + 1);
}

static int	choice_flag_2(int i, t_env *e, va_list *ap,
	const char *restrict s)
{
	if (s[i] == 'x' || s[i] == 'X')
		i = flag_x((unsigned long long)va_arg(*ap, unsigned), i, e, s[i]);
	else if (s[i] == 'u')
		i = flag_u(va_arg(*ap, unsigned long long int), i, e, 0);
	else if (s[i] == 'U')
		i = flag_u(va_arg(*ap, unsigned long long int), i, e, 42);
	else if (s[i] == 'o' || s[i] == 'O')
		i = flag_o(va_arg(*ap, unsigned long long int), i, e, s[i]);
	else if (s[i] == '%')
		i = flag_modu(i, e);
	else if (s[i] == 'f' || s[i] == 'F')
		i = flag_f(va_arg(*ap, double), i, e);
	else if (s[i] == 'd' || s[i] == 'i')
		i = flag_d_i(i, va_arg(*ap, int), e, 0);
	else if (s[i] == 'p')
		i = flag_p(va_arg(*ap, char*), i, e);
	if (s[i] == ' ')
		i = search_param(i, s, e);
	return (i);
}

int			choice_flag(int i, t_env *e, va_list *ap,
	const char *restrict s)
{
	int			s_i;
	uintmax_t	nbr;

	s_i = 0;
	if (s[i] == 'D')
		nbr = va_arg(*ap, uintmax_t);
	while (s_i++ == 0)
	{
		if (s[i] == 'D')
			i = flag_d_i(i, (long long int)nbr, e, 0);
		else if (s[i] == 'c' && e->type_convert[0] != 'l')
			i = flag_c(va_arg(*ap, int), i, e);
		else if (s[i] == 'C' || (s[i] == 'c' && e->type_convert[0] == 'l'))
			i = flag_unsi_c((va_arg(*ap, wchar_t)), e, i);
		else if (s[i] == 's' && e->type_convert[0] != 'l')
			i = flag_s(va_arg(*ap, char*), i, e);
		else if (s[i] == 'S' || (s[i] == 's' && e->type_convert[0] == 'l'))
			i = flag_uni_s(va_arg(*ap, wchar_t*), e, i);
		else if (s[i] == 'p' || s[i] == 'x' || s[i] == 'X' || s[i] == 'u'
		|| s[i] == 'U' || s[i] == 'o' || s[i] == '%' || s[i] == 'f'
		|| s[i] == 'F' || s[i] == 'd' || s[i] == 'i' || s[i] == ' '
		|| s[i] == 'O')
			choice_flag_2(i, e, ap, s);
	}
	return (i);
}
