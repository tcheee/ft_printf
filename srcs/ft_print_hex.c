/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:35:59 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 15:19:52 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_hex(va_list ap)
{
	void				*ptr;
	unsigned long long	addr;

	ptr = va_arg(ap, void*);
	addr = (unsigned long long)ptr;
	ft_putstr("0x");
	ft_putnbr_base(addr, 16);
	return (0);
}
