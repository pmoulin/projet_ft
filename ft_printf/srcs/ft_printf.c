/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:40:19 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 17:07:10 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_param3(t_env *e)
{
	e->pos = 0;
	e->i = 0;
	e->f = 0;
	e->c = 0;
	e->s = 0;
	e->p = 0;
	e->norme = 0;
	e->nega = 0;
	e->c = 0;
	e->u = 0;
	e->o = 0;
	e->modulo = 0;
	e->type_convert[0] = '*';
	e->type_convert[1] = '\0';
	e->t = 0;
	e->t2 = 0;
	e->tv[0] = 0;
	e->tv[1] = 0;
	e->point = 0;
	e->plus = 0;
	e->n = 0;
	e->carac = '\0';
	e->zero = -1;
	e->h_tag = 0;
}

static int	init_param(t_env *e)
{
	e->nega = 0;
	e->pos = 0;
	e->h_tag = 0;
	e->n = 0;
	e->t = 0;
	e->t2 = 0;
	e->tv[0] = 0;
	e->tv[1] = 0;
	e->point = 0;
	e->zero = -1;
	e->plus = 0;
	*e->type_convert = "*\0";
	e->carac = '\0';
	e->line = NULL;
	e->size_line = 0;
	e->i = 0;
	e->f = 0;
	e->c = 0;
	e->s = 0;
	e->p = 0;
	e->c = 0;
	e->u = 0;
	e->o = 0;
	e->modulo = 0;
	return (0);
}

void		ft_error(char *type, char *func)
{
	ft_putstr(type);
	free(type);
	type = NULL;
	ft_putstr("\n--------------\n");
	ft_putstr(func);
	exit(1);
}

static void	browse_format(t_env *e, char *format, va_list *ap, int i1)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(format) && i >= 0 && format[0] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%' && format[i + 1] != '\0')
		{
			i1 = i + 1;
			if ((i = parse_string(format, ap, e, i) + 1) == -1)
				while (format[i1] == ' ')
					i1++;
			i = (i == -1) ? i1 : i;
		}
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				break ;
			i += (format[i] == '%' && format[i + 1] == '%') ? 1 : 0;
			if (format[i] != '\0' && ++e->size_line)
				ft_putchar(format[i++]);
			if (format[i] == '\0')
				break ;
		}
	}
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_env	e;
	int		i;
	int		i1;

	va_start(ap, format);
	i = init_param(&e);
	browse_format(&e, format, &ap, i1);
	if (e.line != NULL)
		free(e.line);
	return (e.size_line);
}
