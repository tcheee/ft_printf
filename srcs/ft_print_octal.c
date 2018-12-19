/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:56:48 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 18:23:13 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_octal(va_list ap, const char *f, int i, int t)
{
	unsigned int		var;
	unsigned long long	var1;
	int				nb;
	int				size;
	int				b;

	nb = 0;
	if (f[i - 1] == 'l' || (f[i - 1] == 'l' && f[i - 2] == 'l'))
	{
		var1 = va_arg(ap, unsigned long long);
		ft_nblen(var1, 8, &nb);
		size = nb;
		flag_space(f, nb, t, &nb);
		flag_hasho(f, t, &nb);
		flag_precision_nb(f, size, t, &nb);
		ft_putnbr_base(var1, 8);
		flag_space_neg(f, nb, t, &nb);
		return (nb);
	}
	else 
		var = va_arg(ap, unsigned int);
	if (f[i - 1] == 'h' && f[i - 2] == 'h')
		var = (char)var;
	else if (f[i - 1] == 'h')
		var = (short)var;
	ft_nblen(var, 8, &nb);
	size = nb;
	b = get_precision(f, t, &nb);
	flag_space_o(f, nb, t, &nb);
	if (var != 0 || (var == 0 && (b == 0 || b == -5)))
		flag_hasho(f, t, &nb);
	flag_precision_nb(f, size, t, &nb);
	if (!((b == 0 || b == -5) && var == 0))
		ft_putnbr_base(var, 8);
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
