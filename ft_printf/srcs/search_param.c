/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:54:17 by phmoulin          #+#    #+#             */
/*   Updated: 2017/12/31 11:54:29 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			search_param(int i, const char *restrict format, t_env *e)
{
	while (format[i] == ' ')
		i++;
	e->t = 1;
	e->tv[0] = 1;
	return (i);
}
