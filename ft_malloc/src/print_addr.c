/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:16:19 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:16:20 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

static int		count_iteration(void *p)
{
	unsigned long	addr;
	int				i;

	i = 0;
	addr = (unsigned long)p;
	while (addr / 16 > 0)
	{
		addr /= 16;
		i++;
	}
	return (i);
}

static char		base(int nb)
{
	char			*base;

	base = "0123456789abcdef";
	return (base[nb]);
}

/*
** void *p : ptr has print
** convert address ptr to string and print this string
*/

void			print_addr(void *p)
{
	unsigned long	addr;
	int				it;
	int				save_it;
	char			res[10];

	it = count_iteration(p);
	save_it = it;
	addr = (unsigned long)p;
	while (addr / 16 > 0)
	{
		res[it] = base((int)addr % 16);
		addr /= 16;
		it -= 1;
	}
	if (it == 13 && addr / 16 == 0)
		res[2] = base((int)p);
	res[it] = base((int)addr % 16);
	res[save_it - it + 1] = '\0';
	malloc_putstr("0x");
	malloc_putstr(res);
}
