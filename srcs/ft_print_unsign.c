/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:04:54 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 15:41:39 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_long_unsign(va_list ap, int nb, t_flag flag)
{
	unsigned long long	var1;
	int					size;

	var1 = va_arg(ap, unsigned long long);
	ft_nblen_unsign(var1, 10, &nb);
	size = nb;
	if (flag.sign != 3)
		flag_space(flag, &nb);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_unsign(var1, 10);
	else
		nb--;
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}

int		ft_print_unsign(va_list ap, t_flag flag)
{
	unsigned int		var;
	int					nb;
	int					size;

	nb = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long_unsign(ap, nb, flag));
	var = va_arg(ap, unsigned int);
	if (flag.hl == 2)
		var = (unsigned char)var;
	else if (flag.hl == 1)
		var = (unsigned short)var;
	ft_nblen(var, 10, &nb);
	size = nb;
	if (flag.sign != 3)
		flag_space(flag, &nb);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_unsign(var, 10);
	else
		nb--;
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
