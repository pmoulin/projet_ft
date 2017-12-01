/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:02:52 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 17:24:55 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		parseur(t_env *env, char *path)
{
	int		fd;

	fd = 0;
	if ((fd = open(path, O_RDONLY)) <= 0)
		ft_error(3);
	read_files(env, fd);
}
