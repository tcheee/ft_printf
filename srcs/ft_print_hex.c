/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:35:59 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:21:50 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_hex(va_list ap, const char *f, int t)
{
	void				*ptr;
	unsigned long long	addr;
	int					nb;

	nb = 0;
	ptr = va_arg(ap, void*);
	addr = (unsigned long long)ptr;
	ft_nblen(addr, 10, &nb);
	flag_space(f, nb, t, &nb);
	ft_putstr("0x");
	ft_putnbr_base(addr, 16);
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
