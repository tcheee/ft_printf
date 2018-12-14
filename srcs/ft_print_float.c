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

int		ft_print_float(va_list ap, const char *f, int i)
{
	double var;
	//int	nb;
	//int size;

	if (f[i - 1] == 'L')
		var = va_arg(ap, long double);
	else
		var = va_arg(ap, double);
	//nb = ft_nblen_double();
	//size = flag_precision(f, nb, t);
	//flag_space(f, nb, t, &nb);
	//flag_hashf(f, t, &nb);
	ft_putnbr_double(var);
	//flag_space_neg(f, nb, t, &nb);
	if (f[i - 1] != 'l')
		var = (float)var;
	return (0);
}
