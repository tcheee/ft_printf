/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:35:59 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 20:11:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_hex(t_flag flag, va_list ap)
{
	void				*ptr;
	unsigned long long	addr;
	int					nb;
	int					size;

	nb = 0;
	ptr = va_arg(ap, void*);
	addr = (unsigned long long)ptr;
	if (!((flag.precis == 0 || flag.precis == -5) && addr == 0))
		ft_nblen(addr, 16, &nb);
	nb += 2;
	size = nb;
	if (flag.zero == 1)
		ft_putstr("0x");
	if (flag.sign != 3 && flag.sign != 4)
		flag_space(flag, &nb);
	if (flag.zero == 0)
		ft_putstr("0x");
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && addr == 0))
		ft_putnbr_base(addr, 16);
	if (flag.space == 3 || flag.space == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
