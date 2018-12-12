/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:49:46 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 15:22:59 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

int		to_round(int nb)
{
	int ret;
	
	ret = nb;
	if (nb % 10 < 5)
		ret = ret / 10;
	else
		ret = (ret / 10) + 1;
	return (ret);
}

// fonction a modifier avec la gestion de la precision!!! car on aura pas forcement 6 chiffres apres la virgule. Essayer de gerer ca en comptant le nombre de virgule apres la virgule grace a des % et /, retourner i puis mettre s = y * (10 * i)

void	ft_putnbr_double(double nb)
{	
	int x;
	double y;
	int		s;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	x = (int)nb;
	ft_putnbr(nb);
	ft_putchar('.');
	y = (nb - x);
	s = y * 10000000;
	s = to_round(s);
	ft_putnbr(s);
}
