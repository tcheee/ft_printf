/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:31:55 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/14 13:21:13 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptrd;
	unsigned char		*ptrs;

	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	if (ptrs < ptrd)
	{
		i = len - 1;
		while (len--)
		{
			ptrd[i] = ptrs[i];
			i--;
		}
	}
	else if (ptrs > ptrd)
	{
		i = 0;
		while (len--)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	return (dst);
}
