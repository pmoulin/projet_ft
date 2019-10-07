/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:16:47 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:16:48 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** t_bloc *bloc: ptr passed in parameter by users.
** size_t size : size needed by users
** spleet on bloc (list chainer) to two bloc
** return : ptr on new bloc with new size
*/

static t_bloc		*spleet_bloc(t_bloc *bloc, size_t size)
{
	t_bloc		*new_bloc;
	size_t		old_size;

	new_bloc = NULL;
	old_size = bloc->size;
	new_bloc = bloc;
	bloc = bloc + size + H_BLOC_SM;
	bloc->status = 0;
	bloc->next = new_bloc->next;
	bloc->prev = new_bloc;
	new_bloc->status = 1;
	new_bloc->next = bloc;
	new_bloc->size = size;
	bloc->size = old_size - (size + H_BLOC_SM);
	return (new_bloc);
}

/*
** t_bloc *bloc: ptr passed in parameter by users.
** size_t size : size needed by users
** create new bloc with new size nedded by users for tiny or small
** and free old bloc
** return ptr on new bloc
*/

static void			*ts_to_ts(t_bloc *bloc, size_t size)
{
	void		*new;
	t_bloc		*save;
	t_bloc		*tmp;

	tmp = NULL;
	save = bloc;
	if (bloc->next)
	{
		bloc = bloc->next;
		if (bloc->status == 0 && bloc->size + save->size >= size + H_BLOC_SM)
		{
			tmp = join_bloc(bloc, bloc->prev);
			tmp = spleet_bloc(tmp, size);
			return (tmp + H_BLOC_SM);
		}
		bloc = bloc->prev;
	}
	if (bloc->size < size + H_BLOC_SM + 1)
		new = malloc(size);
	else
		return ((void *)(new = spleet_bloc(bloc, size) + H_BLOC_SM));
	new = cpy((char*)bloc + H_BLOC_SM, (char*)new, (bloc->size > size)
		? size : bloc->size);
	free(bloc + H_BLOC_SM);
	return (new);
}

/*
** t_zone *zone: ptr passed in parameter by users.
** size_t size : size needed by users
** create new zone, copy old to new zone and delete old zone (for large)
** return ptr on new zone
*/

static void			*large_to_large(t_zone *zone, size_t size)
{
	void		*new;
	size_t		size_cpy;

	size_cpy = (zone->size > size) ? size : zone->size;
	if (!(new = malloc(size)))
		return (NULL);
	new = cpy((char*)zone + H_BLOC_L, (char*)new, size_cpy);
	free((void *)zone + H_BLOC_L);
	return (new);
}

void				*same_type(void *ptr, size_t size, int type)
{
	t_bloc *bloc;
	t_zone *zone;

	zone = NULL;
	bloc = NULL;
	if (type == 1)
	{
		zone = (void *)ptr - H_BLOC_L;
		return (large_to_large(zone, size));
	}
	else if (type == 2 || type == 3)
	{
		bloc = (t_bloc *)ptr - H_BLOC_SM;
		return (ts_to_ts(bloc, size));
	}
	else
		return (NULL);
}
