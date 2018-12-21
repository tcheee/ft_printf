/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:56:48 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 20:36:31 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int		print_long_octal(va_list ap, int nb, t_flag flag)
{
	int size;
	unsigned long long var1;

	var1 = va_arg(ap, unsigned long long);
	ft_nblen(var1, 8, &nb);
	size = nb;
	if (flag.sign != 3)
		flag_space_o(flag, &nb);
	if (var1 != 0 || (var1 == 0 && (flag.precis == 0 || flag.precis == -5)))
		flag_hasho(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_base(var1, 8);
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}

int		ft_print_octal(va_list ap, t_flag flag)
{
	unsigned int		var;
	int					nb;
	int					size;

	nb = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long_octal(ap, nb, flag));
	var = va_arg(ap, unsigned int);
	if (flag.hl == 2)
		var = (char)var;
	else if (flag.hl == 1)
		var = (short)var;
	if (!(var == 0 && (flag.precis == -5 || flag.precis == 0) && flag.hash == 0))
		ft_nblen(var, 8, &nb);
	size = nb;
	if (flag.hash == 1 && var != 0)
		nb++;
	if (flag.sign != 3)
		flag_space_o(flag, &nb);
	if (var != 0 || (var == 0 && (flag.precis == 0 || flag.precis == -5)))
		flag_hasho(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_base(var, 8);
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
