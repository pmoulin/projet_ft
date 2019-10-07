/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:16:25 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:16:28 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

static int		nb_elem(size_t nb)
{
	int		i;

	i = 0;
	while (nb / 10 > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static void		print(int nb_elem, size_t nb)
{
	int			i;
	char		dest[nb_elem + 1];

	i = nb_elem;
	while (nb)
	{
		dest[i] = ((nb % 10) + 48);
		nb = nb / 10;
		i--;
	}
	dest[nb_elem + 1] = '\0';
	malloc_putstr(dest);
}

/*
** size_t number : number has print
** convert the number passed in parameter to string
** and print the string. (ft_putnbr);
*/

void			print_size(size_t number)
{
	int				nb_elem_in_number;

	nb_elem_in_number = nb_elem(number);
	if (number <= 9)
		malloc_putchar(number + 48);
	else
		print(nb_elem_in_number, number);
}
