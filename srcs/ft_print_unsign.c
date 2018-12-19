/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:04:54 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 17:32:27 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_unsign(va_list ap, const char *f, int i, int t)
{
	unsigned int		var;
	unsigned long long	var1;
	int					nb;
	int					size;
	int					b;

	nb = 0;
	if (f[i - 1] == 'l' || (f[i - 1] == 'l' && f[i - 2] == 'l'))
	{
		var1 = va_arg(ap, unsigned long long);
		ft_nblen_unsign(var1, 10, &nb);
		size = nb;
		flag_space(f, nb, t, &nb);
		flag_precision_nb(f, size, t, &nb);
		ft_putnbr_unsign(var1, 10);
		flag_space_neg(f, nb, t, &nb);
		return (nb);
	}
	else 
		var = va_arg(ap, unsigned int);
	if (f[i - 1] == 'h' && f[i - 2] == 'h')
		var = (char)var;
	else if (f[i - 1] == 'h')
		var = (short)var;
	ft_nblen(var, 10, &nb);
	size = nb;
	flag_space(f, nb, t, &nb);
	b = flag_precision_nb(f, size, t, &nb);
	if (!((b == 0 || b == -5) && var == 0))
		ft_putnbr_base(var, 10);
	else
		nb--;
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
