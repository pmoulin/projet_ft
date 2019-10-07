/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:16:40 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:16:42 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** void *ptr : ptr on the memory to realocated
** check if memory is a large type
** if type of memory = large
** return (int): 1;
** else
** return (int) : 0;
*/

static int			check_large(void *ptr)
{
	if (g_env_m.z_large)
	{
		while (g_env_m.z_large)
		{
			if (g_env_m.z_large == ((void *)ptr - H_BLOC_L))
				return (1);
			else if (!g_env_m.z_large->next)
				break ;
			g_env_m.z_large = g_env_m.z_large->next;
		}
	}
	g_env_m.z_large = go_first_maillon(NULL, g_env_m.z_large);
	return (0);
}

/*
** void *ptr : ptr on the memory to realocated
** detect type of memory passed in parameter and return this type.
** ret :
** 1 = large;
** 2 = small;
** 3 = tiny;
*/

static int			check_type_ptr(void *ptr)
{
	t_bloc *bloc;

	bloc = NULL;
	if (check_large(ptr) == 1)
		return (1);
	else
	{
		bloc = (t_bloc *)ptr - H_BLOC_SM;
		if (bloc->size > (size_t)(getpagesize() / 2)
			&& bloc->size <= (size_t)(getpagesize() * 5) / 2)
			return (2);
		else
			return (3);
	}
}

/*
** size_t size : size need by users
** detect type of memory for the new bloc and return this type.
** ret :
** 1 = large;
** 2 = small;
** 3 = tiny;
*/

static int			def_type_new_bloc(size_t size)
{
	if (size > ((size_t)(getpagesize() * 5) / 2))
		return (1);
	else if (size > (size_t)(getpagesize() / 2)
		&& size <= (size_t)(getpagesize() * 5) / 2)
		return (2);
	else
		return (3);
}

/*
** void *ptr : old ptr;
** size_t size : size for the new alloc needed by users;
** check new type of memory nedded
** rellocated the momery of type (and size) needed and delete old memory
** return ptr on the new memory demander
** or
** return NULL if error;
*/

void				*realloc(void *ptr, size_t size)
{
	int	type_ptr;
	int	type_new_ptr;

	type_ptr = check_type_ptr(ptr);
	type_new_ptr = def_type_new_bloc(size);
	if (type_new_ptr == type_ptr)
		return (same_type(ptr, size, type_ptr));
	else
		return (convert_type(ptr, size, type_ptr, type_new_ptr));
	return (NULL);
}
