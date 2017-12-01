/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:27:46 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/16 11:27:50 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*next_list;

	if (!alst)
		return ;
	list = *alst;
	while (list)
	{
		next_list = list->next;
		del(list->content, list->content_size);
		free(list);
		list = next_list;
	}
	*alst = NULL;
}
