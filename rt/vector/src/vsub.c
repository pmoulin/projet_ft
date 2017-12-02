/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsub.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:49:12 by shamdani          #+#    #+#             */
/*   Updated: 2017/01/11 17:24:10 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	vsub(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}
