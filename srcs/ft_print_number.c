/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:15:37 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:21:48 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_number(va_list ap, const char *f, int i, int t)
{
	int	var;
	int	nb;

	nb = 0;
	if (f[i - 1] == 'l' && f[i - 2] == 'l')
		var = va_arg(ap, long long);
	else if (f[i - 1] == 'l')
		var = va_arg(ap, long);
	else
		var = va_arg(ap, int);
	if (f[i - 1] == 'h' && f[i - 2] == 'h')
		var = (char)var;
	else if (f[i - 1] == 'h')
		var = (short)var;
	ft_nblen(var, 10, &nb);
	flag_space(f, nb, t, &nb);
	ft_putnbr_base(var, 10);
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
