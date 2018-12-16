/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:49:46 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 20:25:45 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

int		to_round(int nb, int tmp)
{
	int ret;
	
	ret = nb;
	if (tmp >= 5)
		ret = ret + 1;
	return (ret);
}

void	ft_putnbr_double(double nb, int size)
{	
	int x;
	int i;
	double y;
	double tmp;
	unsigned long long	ret;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	x = (unsigned long long)nb;
	ft_putnbr_base(nb, 10);
	ft_putchar('.');
	y = (nb - x);
	tmp = y;
	tmp = tmp * 10;
	while ((int)tmp == 0 && i < size)
	{
		ft_putnbr(0);
		tmp = tmp * 10;
		i++;
	}
	while (i < size)
	{
		if (((int)tmp%10) != 0)
		{
			ret = (unsigned long long)tmp % 10;
			if (i == size - 1)
				ret = to_round(ret, (int)(tmp * 10) % 10);
			ft_putnbr_base(ret, 10);
		}
		else
			ft_putnbr(0);
		tmp = tmp * 10;
		i++;
	}
}
