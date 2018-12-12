/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:43:36 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/22 15:06:08 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*new;

	i = 0;
	j = 0;
	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	if (!(new = (char *)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (i == start && j < len)
		{
			new[j] = s[i];
			j++;
			i++;
			start++;
		}
		else
			i++;
	}
	new[j] = '\0';
	return (new);
}
