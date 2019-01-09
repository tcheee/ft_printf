/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhexX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:06:22 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 17:28:02 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		gain_space(t_flag flag, int *nb)
{
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, *nb, nb);
	return (*nb);
}

static void		get_var_uhexmaj(t_flag flag, unsigned int *var)
{
	if (flag.hl == 2)
		*var = (unsigned char)(*var);
	else if (flag.hl == 1)
		*var = (unsigned short)(*var);
}

int				print_long_uhexmaj(va_list ap, int nb, t_flag flag)
{
	int					size;
	unsigned long long	var1;

	var1 = va_arg(ap, unsigned long long);
	if (!(var1 == 0 && flag.precis == -5) && !(var1 == 0 && flag.precis == 0))
		ft_nblen_unsign(var1, 16, &nb);
	size = nb;
	if (flag.hash == 1 && var1 != 0)
		nb = nb + 2;
	if (flag.hash == 1 && flag.zero == 1)
		flag_hashxmaj(flag);
	if (flag.sign != 3)
		flag_space_x(flag, &nb);
	if (var1 != 0 && flag.zero == 0)
		flag_hashxmaj(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_unsign_maj(var1, 16);
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}

int				ft_print_uhexmaj(va_list ap, t_flag flag)
{
	unsigned int		var;
	int					nb;
	int					size;

	nb = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long_uhexmaj(ap, nb, flag));
	var = va_arg(ap, unsigned int);
	get_var_uhexmaj(flag, &var);
	flag.neg = (var == 0 ? 1 : 0);
	if (!(var == 0 && (flag.precis == -5 || flag.precis == 0)))
		ft_nblen(var, 16, &nb);
	size = nb;
	nb = ((flag.hash == 1 && var != 0 && flag.precis < size) ? nb + 2 : nb);
	if (var != 0 && flag.hash == 1 && flag.zero == 1 && flag.space == 0)
		flag_hashxmaj(flag);
	if (flag.sign != 3)
		flag_space_x(flag, &nb);
	if (var != 0 && ((flag.zero == 0) || (flag.zero == 1 && flag.space > 0)))
		flag_hashxmaj(flag);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_basemaj(var, 16);
	return (gain_space(flag, &nb));
}
