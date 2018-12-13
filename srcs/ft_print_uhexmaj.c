/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhexX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:06:22 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:21:25 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_uhexmaj(va_list ap, const char *f, int i, int t)
{
	unsigned int	var;
	int				nb;

	nb = 0;
	if (f[i - 1] == 'l' && f[i - 2] == 'l')
		var = va_arg(ap, long long);
	else if (f[i - 1] == 'l')
		var = va_arg(ap, long);
	else 
		var = va_arg(ap, unsigned int);
	if (f[i - 1] == 'h' && f[i - 2] == 'h')
		var = (char)var;
	else if (f[i - 1] == 'h')
		var = (short)var;
	ft_nblen(var, 16, &nb);
	flag_space(f, nb, t, &nb);
	ft_putnbr_basemaj(var, 16);
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
