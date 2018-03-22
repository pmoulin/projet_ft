/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_conv_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:47:19 by phmoulin          #+#    #+#             */
/*   Updated: 2018/03/10 16:00:47 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			choice_flag_unsi(t_env *e, const char *restrict format, int i,
intmax_t nbr)
{
	int		s_i;

	s_i = 0;
	while (s_i++ == 0)
	{
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'D')
			i = flag_d_i(i, (long long int)nbr, e, 0);
		else if (format[i] == 'x' || format[i] == 'X')
			i = flag_x((unsigned long long int)nbr, i, e, format[i]);
		else if (format[i] == 'u' || format[i] == 'U')
			i = flag_u((unsigned long long int)nbr, i, e, 0);
		else if (format[i] == 'o' || format[i] == 'O')
			i = flag_o((unsigned long long int)nbr, i, e, format[i]);
		if (format[i] == ' ')
			i = search_param(i, format, e);
	}
	return (i);
}

int			choice_param_unsigned(va_list *ap, t_env *e,
const char *restrict s, int i)
{
	uintmax_t	nbr;

	if (s[i] != 'd' && s[i] != 'i' && s[i] != 'D')
		nbr = va_arg(*ap, uintmax_t);
	else
		e->norme = choice_param_unsigned_d_i(ap, e, s, i);
	if ((s[i] == 'U' || s[i] == 'O')
	&& ft_strcmp(e->type_convert, "hh") == 0 && e->norme == 0)
		nbr = (long long int)nbr;
	else if (ft_strcmp(e->type_convert, "hh") == 0 && e->norme == 0)
		nbr = (unsigned char)nbr;
	else if (ft_strcmp(e->type_convert, "h") == 0 && e->norme == 0)
		nbr = (e->u == 2) ? (unsigned long long int)nbr : (unsigned short)nbr;
	else if ((ft_strcmp(e->type_convert, "l") == 0 || e->norme == 0
	|| ft_strcmp(e->type_convert, "ll") == 0) && e->norme == 0)
		nbr = (unsigned long long int)nbr;
	else if (ft_strcmp(e->type_convert, "j") == 0 && e->norme == 0)
		nbr = (uintmax_t)nbr;
	else if (ft_strcmp(e->type_convert, "z") == 0 && e->norme == 0)
		nbr = (size_t)nbr;
	else if (e->norme == 0)
		nbr = (unsigned int)nbr;
	if (e->norme == 0)
		i = choice_flag_unsi(e, s, i, nbr);
	return (i);
}

uintmax_t	choice_param_unsigned_d_i(va_list *ap, t_env *e,
const char *restrict s, int i)
{
	uintmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	if (ft_strcmp(e->type_convert, "hh") == 0 && s[i] == 'D')
		nbr = (signed long long int)nbr;
	else if (ft_strcmp(e->type_convert, "hh") == 0 && (s[i] == 'd' ||
	s[i] == 'i'))
		nbr = (char)nbr;
	else if (ft_strcmp(e->type_convert, "h") == 0 && s[i] == 'D')
		nbr = (unsigned short)nbr;
	else if (ft_strcmp(e->type_convert, "h") == 0 && (s[i] == 'd' ||
	s[i] == 'i'))
		nbr = (signed short)nbr;
	else if (ft_strcmp(e->type_convert, "l") == 0)
		nbr = (long int)nbr;
	else if (ft_strcmp(e->type_convert, "ll") == 0)
		nbr = (long long int)nbr;
	else if (ft_strcmp(e->type_convert, "j") == 0)
		nbr = (intmax_t)nbr;
	else if (ft_strcmp(e->type_convert, "z") != 0)
		nbr = (unsigned int)nbr;
	i = choice_flag_unsi(e, s, i, nbr);
	return (i);
}
