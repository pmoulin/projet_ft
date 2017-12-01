/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:40:22 by phmoulin          #+#    #+#             */
/*   Updated: 2017/02/23 10:41:41 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_alloc_y(t_global *global, char *line, char *path)
{
	int		i;
	int		fd;

	i = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		ft_error(3);
	while (ft_get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	if (!(global->pos = (t_point ***)malloc(sizeof(t_point **) * (i + 1))))
		ft_error(2);
	global->pos[i] = NULL;
	close(fd);
	return (1);
}
