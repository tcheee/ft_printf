/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:23:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 20:18:21 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_float(va_list ap, const char *f, int i, int t)
{
	double var;
	int	nb;
	int size;

	nb = 0;
	if (f[i - 1] == 'L')
		var = va_arg(ap, long double);
	else
		var = va_arg(ap, double);
	ft_nblen_double(var, &nb);
	size = flag_precision(f, nb, t);
	if (size == -1)
		size = 6;
	else if (size > 0)
		nb = nb - (6 - size);
	//ft_putnbr(size);
	//ft_putchar('\n');
	flag_space(f, nb, t, &nb);
	if (size <= 0)
	{
		nb = nb - 7;
		ft_putnbr((int)var);
	}
	else
		ft_putnbr_double(var, size);
	if (size <= 0)
		flag_hashf(f, t, &nb);
	flag_space_neg(f, nb, t, &nb);
	if (f[i - 1] != 'l')
		var = (float)var;
	return (nb);
}
