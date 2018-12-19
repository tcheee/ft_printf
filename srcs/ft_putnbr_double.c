/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:49:46 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 10:38:19 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

static char	*ft_dtoa(long double nb, int size)
{
	unsigned long long	len;
	long long			tmp;
	char				*str;
	int					n;

	n = 0;
	len = size + 2;
	if (!(str = (char*)malloc(sizeof(*str) * (len) + 1)))
		return (NULL);
	str[len] = '\0';
	str[0] = '.';
	while (++n <= (int)(len - 1))
	{
		tmp = (long long)nb;
		nb -= (long double)tmp;
		nb *= 10;
		str[n] = '0' + ((int)nb % 10);
	}
	return (str);
}

void	ft_putnbr_double(double nb, int size)
{
	char	*pint;
	char	*test;
	int		n;
	int		tmp;

	n = 0;
	pint = ft_itoa(nb);
	test = ft_dtoa(nb, size);
	pint = ft_strjoin_free(pint, test);
	while (pint[n])
		n++;
	n--;
	tmp = n;
	if (pint[n] >= '5' && pint[n] <= '9')
	{
		while (pint[--n] == '9')
			pint[n] = '0';
		pint[n] += 1;
	}
	pint[tmp] = '\0';
	ft_putnstr(pint, tmp);
}
