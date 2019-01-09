/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:56:48 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 18:45:46 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		gain_space(t_flag flag, int *nb)
{
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, *nb, nb);
	return (*nb);
}

static void		get_var_octal(t_flag flag, unsigned int *var)
{
	if (flag.hl == 2)
		*var = (unsigned char)(*var);
	else if (flag.hl == 1)
		*var = (unsigned short)(*var);
}

int				print_long_octal(va_list ap, int nb, t_flag flag)
{
	int					size;
	unsigned long long	var1;

	var1 = va_arg(ap, unsigned long long);
	if (!(var1 == 0 && (flag.precis == -5
					|| flag.precis == 0) && flag.hash == 0))
		ft_nblen_unsign(var1, 8, &nb);
	size = nb;
	if (flag.hash == 1 && ((var1 != 0 && flag.precis <= size)))
		nb++;
	if (flag.sign != 3)
		flag_space_o(flag, &nb);
	if ((var1 != 0 && flag.precis <= size) ||
			(var1 == 0 && (flag.precis == 0 || flag.precis == -5)))
		flag_hasho(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_unsign(var1, 8);
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}

int				ft_print_octal(va_list ap, t_flag flag)
{
	unsigned int		var;
	int					nb;
	int					siz;

	nb = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long_octal(ap, nb, flag));
	var = va_arg(ap, unsigned int);
	get_var_octal(flag, &var);
	if (!(var == 0 && (flag.precis == -5
					|| flag.precis == 0) && flag.hash == 0))
		ft_nblen(var, 8, &nb);
	siz = nb;
	nb = ((flag.hash == 1 && ((var != 0 && flag.precis <= siz))) ? nb + 1 : nb);
	if (flag.sign != 3)
		flag_space_o(flag, &nb);
	if ((var != 0 && flag.precis <= siz) ||
			(var == 0 && (flag.precis == 0 || flag.precis == -5)))
		flag_hasho(flag);
	flag_precision_nb(flag, siz, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_base(var, 8);
	return (gain_space(flag, &nb));
}
