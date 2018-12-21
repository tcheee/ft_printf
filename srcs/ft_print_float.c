/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:23:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 13:33:37 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_float(va_list ap, const char *f, int t, t_flag flag)
{
	double	var;
	int		nb;
	int		tmp;

	nb = 0;
	if (flag.hash == 5 || flag.hash == 3)
		var = va_arg(ap, long double);	
	var = va_arg(ap, double);	
	ft_nblen_double(var, &nb);
	if (flag.precis == -1)
		flag.precis = 6;
	else if (flag.precis > 0)
		nb -= (flag.precis);
	if (flag.sign == 1 || flag.sign == 3)
	{
		flag.sign == 1 ? ft_putchar('+') : ft_putchar('-');
		nb++;
	}
	if (flag.precis <= 0)
	{
		tmp = 0;
		ft_nblen((long long)var, 10, &tmp);
		flag_space(flag.space, tmp, flag.zero, &nb);
		nb = nb - 7;
		ft_putnbr((int)var);
	}
	else
	{
		tmp = flag.precis + 1;
		ft_nblen((long long)var, 10, &tmp);
		flag_space(flag.space, tmp, flag.zero, &tmp);
		ft_putnbr_double(var, flag.precis);
		nb = tmp++;
	}
	if (flag.precis <= 0 && get_hash(f, t) != 0)
	{
		ft_putchar('.');
		nb++;
	}
	return (nb);
}
