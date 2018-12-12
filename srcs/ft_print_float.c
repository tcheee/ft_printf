/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:23:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 14:33:37 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_float(va_list ap, const char *f, int i)
{
	double var;

	if (f[i - 1] == 'L')
		var = va_arg(ap, long double);
	else
		var = va_arg(ap, double);
	ft_putnbr_double(var);
	if (f[i - 1] != 'l')
		var = (float)var;
	return (0);
}
