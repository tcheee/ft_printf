/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:05:47 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 17:29:07 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		get_var_uhex(t_flag flag, unsigned int *var, va_list ap)
{
	*var = va_arg(ap, unsigned int);
	if (flag.hl == 2)
		*var = (unsigned char)(*var);
	else if (flag.hl == 1)
		*var = (unsigned short)(*var);
}

int				print_long_uhex(va_list ap, int nb, t_flag flag)
{
	int					size;
	unsigned long long	var1;

	var1 = va_arg(ap, unsigned long long);
	if (!(var1 == 0 && (flag.precis == -5 || flag.precis == 0)))
		ft_nblen_unsign(var1, 16, &nb);
	size = nb;
	if (flag.hash == 1 && var1 != 0)
		nb = nb + 2;
	if (flag.hash == 1 && flag.zero == 1)
		flag_hashx(flag);
	if (flag.sign != 3)
		flag_space_x(flag, &nb);
	if (var1 != 0 && flag.zero == 0)
		flag_hashx(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_unsign(var1, 16);
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}

int				ft_print_uhex(va_list ap, t_flag flag)
{
	unsigned int		var;
	int					nb;
	int					size;

	nb = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long_uhex(ap, nb, flag));
	get_var_uhex(flag, &var, ap);
	flag.neg = ((var == 0) ? 1 : 0);
	if (!(var == 0 && (flag.precis == -5 || flag.precis == 0)))
		ft_nblen(var, 16, &nb);
	size = nb;
	nb = ((flag.hash == 1 && var != 0 && flag.precis < size) ? nb + 2 : nb);
	if (var != 0 && flag.hash == 1 && flag.zero == 1
			&& !(flag.space > 0 && flag.precis != -10))
		flag_hashx(flag);
	if (flag.sign != 3)
		flag_space_x(flag, &nb);
	if (flag.hash == 1 && var != 0 && ((flag.zero == 0)
				|| (flag.space > 0 && flag.precis != -10)))
		flag_hashx(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_base(var, 16);
	return (ender(flag, &nb));
}
