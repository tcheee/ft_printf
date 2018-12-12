/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:45:38 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/13 10:55:17 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0)
		return (NULL);
	if (*need == '\0')
		return ((char*)hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == need[j] && hay[i + j] != '\0' && need[j] != '\0'
				&& (i + j) < len)
			j++;
		if (need[j] == '\0')
			return ((char *)&hay[i]);
		i++;
	}
	return (NULL);
}
