/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_like.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:45:24 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 16:59:09 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_like_2(t_env *e, int i, char c)
{
	while (e->line[i])
	{
		if (e->line[i] != '\0')
		{
			ft_putchar(e->line[i]);
			e->size_line++;
		}
		else if (e->line[i] == '\0' && e->zero != 0)
		{
			write(1, &c, 1);
			e->size_line++;
		}
		i++;
		if (i == e->zero && e->size_line++)
			write(1, &c, 1);
	}
	return (i);
}

int			ft_putstr_like(t_env *e, int x)
{
	int			i;
	char		c;

	c = '\0';
	i = 0;
	if (e->line[i])
	{
		if (e->line[i] == 'n' && e->line[i + 1] == 'u' && e->line[i + 2] == 'l'
		&& e->line[i + 3] == 'l')
		{
			while (x++ < 5)
				ft_putchar(e->line[i++]);
			e->size_line += 1;
		}
		i = ft_putstr_like_2(e, i, c);
	}
	else if (e->zero != -1 && e->zero == i + 1)
	{
		write(1, &c, 1);
		e->size_line++;
		i++;
	}
	if (e->line != NULL)
		ft_strdel(&e->line);
	return (i);
}
