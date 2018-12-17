/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:07:17 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/17 17:15:24 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

void	ft_putnbr_unsign(unsigned long long nb, int base)
{
	if (nb < (unsigned long long)base)
	{
		if (nb < 10)
			ft_putchar('0' + nb);
		else
			ft_putchar('a' + (nb - 10));
		return ;
	}
	ft_putnbr_unsign(nb / base, base);
	ft_putnbr_unsign(nb % base, base);
}
