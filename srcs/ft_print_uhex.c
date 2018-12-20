/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:05:47 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/20 20:41:38 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_long_uhex(va_list ap, const char *f, int nb, t_flag flag)
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
}

int		ft_print_uhex(va_list ap, const char *f, int t, t_flag flag)
{
	unsigned int		var;
	int				nb;
	int				size;
	int				b;
	int				k;

	nb = 0;
	k = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long_uhex(ap, f, nb, flag));
	var = va_arg(ap, unsigned int);
	if (f[i - 1] == 'h' && f[i - 2] == 'h')
		var = (char)var;
	else if (f[i - 1] == 'h')
		var = (short)var;
	ft_nblen(var, 16, &nb);
	size = nb;
	if (get_precision2(f, t) <= 0 && var == 0)
	{
		nb--;
		k = 1;
	}
	b = flag_space_x(f, nb, t, &nb);
	if (var != 0 && b != -1)
		flag_hashx(f, t, &nb);
	b = flag_precision_nb(f, size, t, &nb);
	if (!((b == 0 || b == -5) && var == 0))
		ft_putnbr_base(var, 16);
	else if (((b == 0 || b == -5) && var == 0 && k == 0))
		nb--;
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
