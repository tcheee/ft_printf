/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:49:46 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 18:46:26 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_dtoa(long double nb, int size)
{
	unsigned long long	len;
	long long			tmp;
	char				*str;
	int					n;

	n = 0;
	len = size + 2;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
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
	ft_putstr(str);
	return (str);
}

void			ft_putnbr_double(double nb, int size)
{
	char	*pint;
	char	*test;
	int		n;
	int		tmp;

	n = 0;
	pint = ft_itoa(nb);
	ft_putstr(pint);
	ft_putchar('\n');
	test = ft_dtoa(nb, size);
	ft_putstr(test);
	ft_putchar('\n');
	pint = ft_strjoin_free(pint, test);
	ft_putstr("bug2\n");
	ft_putstr(pint);
	while (pint[n] != '\0')
		n++;
	ft_putstr("bug3\n");
	n--;
	tmp = n;
	ft_putstr("bug4\n");
	if (pint[n] >= '5' && pint[n] <= '9')
	{
		while (pint[--n] == '9')
			pint[n] = '0';
		pint[n] += 1;
	}
	ft_putstr("bug55555\n");
	pint[tmp] = '\0';
	ft_putstr("bug\n");
	ft_putnstr(pint, tmp);
}
