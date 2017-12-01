/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:17:10 by phmoulin          #+#    #+#             */
/*   Updated: 2016/11/16 12:27:29 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		d;
	int		z;
	char	*dest;

	if (!s)
		return (NULL);
	z = ft_strlen(s) - 1;
	d = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (i != z))
		i++;
	if (i == z)
		return (ft_strdup(""));
	while ((s[z] == ' ' || s[z] == '\n' || s[z] == '\t') && (i != z))
		z--;
	z += 1;
	if ((dest = (char *)malloc(((z - i) + 1) * sizeof(dest))) == NULL)
		return (NULL);
	while (i < z)
		dest[d++] = s[i++];
	dest[d] = '\0';
	return (dest);
}
