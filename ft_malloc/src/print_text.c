/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:58:17 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/16 14:58:19 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void		malloc_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, str, i);
		i++;
	}
}

void		malloc_putchar(char c)
{
	write(1, &c, 1);
}
