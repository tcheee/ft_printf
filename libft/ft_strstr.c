/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:38:34 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/10 12:13:53 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *need)
{
	int	i;
	int	j;

	i = 0;
	if (need == hay)
		return ((char*)hay);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == need[j] && hay[i + j] != '\0' && need[j] != '\0')
			j++;
		if (need[j] == 0)
			return ((char *)&hay[i]);
		i++;
	}
	return (NULL);
}
