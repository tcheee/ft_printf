/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:24:23 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/13 13:09:15 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size_char(long nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int nb)
{
	char	*s;
	int		i;
	long	n;

	n = nb;
	i = size_char(n) - 1;
	if (!(s = (char *)malloc(sizeof(*s) * (size_char(n) + 1))))
		return (NULL);
	s[size_char(n)] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[i] = '0' + n % 10;
		n = n / 10;
		i--;
	}
	return (s);
}
