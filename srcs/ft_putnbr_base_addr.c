/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_addr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:10:55 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/17 12:18:47 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base_addr(unsigned long long nb, int base, int *ret)
{
	if (nb < (unsigned long long)base)
	{
		if (nb < 10)
		{
			ft_putchar('0' + nb);
			(*ret)++;
		}
		else
		{
			ft_putchar('a' + (nb - 10));
			(*ret)++;
		}
		return ;
	}
	ft_putnbr_base_addr(nb / base, base, ret);
	ft_putnbr_base_addr(nb % base, base, ret);
}
