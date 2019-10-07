/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:15:28 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:17:33 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** realoc Large to tiny or small and free old ptr
** return new(void *) pointer on new zoned
*/

static void		*large_to_ts(void *ptr, size_t size)
{
	void	*new;
	t_zone	*large;
	size_t	size_cpy;

	large = NULL;
	large = ((void *)ptr - H_BLOC_L);
	size_cpy = (large->size > size) ? size : large->size;
	if (!(new = malloc(size)))
		return (NULL);
	new = cpy((char*)ptr, (char*)new, size_cpy);
	free(ptr);
	return (new);
}

/*
** realoc tiny or small to Large and free old ptr
** return new(void *) pointer on Large zoned
*/

static void		*ts_to_large(void *ptr, size_t size)
{
	void		*new;
	t_bloc		*bloc;
	size_t		size_cpy;

	new = NULL;
	bloc = NULL;
	if (!(new = malloc(size)))
		return (NULL);
	bloc = (t_bloc *)ptr - H_BLOC_SM;
	size_cpy = (bloc->size > size) ? size : bloc->size;
	new = cpy((char*)ptr, (char*)new, size_cpy);
	free(ptr);
	return (new);
}

/*
** realoc tiny to small or small to tiny and free old ptr
** return new(void *) pointer on tiny or small zoned
*/

static void		*ts_to_ts(void *ptr, size_t size)
{
	void		*new;
	t_bloc		*bloc;
	size_t		size_cpy;

	bloc = NULL;
	new = NULL;
	bloc = (t_bloc *)ptr - H_BLOC_SM;
	size_cpy = (bloc->size > size) ? size : bloc->size;
	if (!(new = malloc(size)))
		return (NULL);
	new = cpy((char*)ptr, (char*)new, size_cpy);
	free(ptr);
	return (new);
}

/*
** Compare type and convert
** large_to_ts()	: convert large to tiny OR small
** ts_to_large()	: convert tiny OR small to Large
** ts_to_ts()		: convert tiny to small OR small to tiny
**
** 1 = large
** 2 = small
** 3 = tiny
*/

void			*convert_type(void *ptr, size_t size,
	int type_ptr, int new_type)
{
	if ((type_ptr == 2 || type_ptr == 3) && (new_type == 1))
	{
		return (ts_to_large(ptr, size));
	}
	else if ((type_ptr == 1) && (new_type == 2 || new_type == 3))
	{
		return (large_to_ts(ptr, size));
	}
	else if ((type_ptr == 2 || type_ptr == 3)
		&& (new_type == 2 || new_type == 3)
		&& (new_type != type_ptr))
	{
		return (ts_to_ts(ptr, size));
	}
	return (NULL);
}
