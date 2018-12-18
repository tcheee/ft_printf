/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:52:33 by ayguillo          #+#    #+#             */
/*   Updated: 2018/11/23 10:55:29 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	n;

	dst2 = (char*)dst;
	src2 = (char*)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst2 < src2)
	{
		n = 0;
		while (n < len)
		{
			dst2[n] = src2[n];
			n++;
		}
	}
	else
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
	return (dst);
}
