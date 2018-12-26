/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:05:47 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 20:35:26 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// pas oublier de recopier 	if (!(var == 0 && flag.precis == -5) && !(var == 0 && flag.precis == 0)) dans les print long de chaque fonction


int		print_long_uhex(va_list ap, int nb, t_flag flag)
{
	int size;
	unsigned long long var1;

	var1 = va_arg(ap, unsigned long long);
	if (!(var1 == 0 && flag.precis == -5) && !(var1 == 0 && flag.precis == 0))
		ft_nblen(var1, 16, &nb);
	size = nb;
	if (flag.hash == 1 && var1 != 0)
		nb = nb + 2;
	if (flag.hash == 1 && flag.zero == 1)
		flag_hashx(flag);
	if (flag.sign != 3)
		flag_space(flag, &nb);
	if (var1 != 0 && flag.zero == 0)
		flag_hashx(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_base(var1, 16);
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}

int		ft_print_uhex(va_list ap, t_flag flag)
{
	unsigned int		var;
	int					nb;
	int					size;

	nb = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long_uhex(ap, nb, flag));
	var = va_arg(ap, unsigned int);
	if (flag.hl == 2)
		var = (char)var;
	else if (flag.hl == 1)
		var = (short)var;
	if (!(var == 0 && flag.precis == -5) && !(var == 0 && flag.precis == 0))
		ft_nblen(var, 16, &nb);
	size = nb;
	if (flag.hash == 1 && var != 0)
		nb = nb + 2;
	if (flag.hash == 1 && flag.zero == 1)
		flag_hashx(flag);
	if (flag.sign != 3)
		flag_space(flag, &nb);
	if (var != 0 && flag.zero == 0)
		flag_hashx(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_base(var, 16);
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
