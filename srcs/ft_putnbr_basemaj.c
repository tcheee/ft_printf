/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_baseA.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:07:08 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/17 17:00:03 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_basemaj(long long nb, int base)
{
	if (nb < (long long)base)
	{
		if (nb < 10)
			ft_putchar('0' + nb);
		else
			ft_putchar('A' + (nb - 10));
		return ;
	}
	ft_putnbr_basemaj(nb / base, base);
	ft_putnbr_basemaj(nb % base, base);
}
