/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:35:59 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 11:53:17 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_hex(t_flag flag, va_list ap)
{
	void				*ptr;
	unsigned long long	addr;
	int					nb;

	nb = 0;
	ptr = va_arg(ap, void*);
	addr = (unsigned long long)ptr;
	flag_space(flag.space, nb, flag.zero, &nb);
	ft_putstr("0x");
	nb +=2;
	ft_putnbr_base_addr(addr, 16, &nb);
	flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
