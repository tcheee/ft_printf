/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:05:47 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 14:09:11 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*int		print_long_uhex(va_list ap, const char *f, int nb, t_flag flag)
{
	int size;
	unsigned long long var1;

	var1 = va_arg(ap, unsigned long long);
	ft_nblen(var1, 16, &nb);
	size = nb;
	flag_space_x(f, nb, t, &nb);
	flag_hashx(f, t, &nb);
	flag_precision_nb(f, size, t, &nb);
	ft_putnbr_base(var1, 16);
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}*/

int		ft_print_uhex(va_list ap, t_flag flag)
{
	unsigned int		var;
	int					nb;
	int					size;
	int					k;

	nb = 0;
	k = 0;
	/*if (flag.hl == 4 || flag.hl == 3)
		return (print_long_uhex(ap, f, nb, flag));*/
	var = va_arg(ap, unsigned int);
	if (flag.hl == 2)
		var = (char)var;
	else if (flag.hl == 1)
		var = (short)var;
	ft_nblen(var, 16, &nb);
	size = nb;
	/*if (get_precision2(f, t) <= 0 && var == 0)
	{
		nb--;
		k = 1;
	}*/
	if (flag.sign != 3)
		flag_space(flag.space, nb, flag.zero, &nb);
	if (var != 0)
		flag_hashx(flag, &nb);
	flag_precision_nb(flag.precis, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_base(var, 16);
	else if (((flag.precis == 0 || flag.precis == -5) && var == 0 && k == 0))
		nb--;
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
