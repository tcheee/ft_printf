/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:13:55 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/15 17:29:16 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char)c)
		{
			ptr_d[i] = ptr_s[i];
			return ((char*)&ptr_d[i + 1]);
		}
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (NULL);
}
