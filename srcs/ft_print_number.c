/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:15:37 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 17:28:30 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_lld_max(int nb, long long var1)
{
	unsigned long long n;

	n = -var1;
	ft_putchar('-');
	nb++;
	ft_putnbr_unsign(n, 10);
	ft_nblen_unsign(n, 10, &nb);

	//  a faire: gerer les espaces et les precision & co
	return (nb);
}

int		ft_print_number(va_list ap, const char *f, int t)
{
	int	var;
	long long var1;
	int	nb;
	int size;
	int	b;

	nb = 0;
	b = check_flag_hl(f, t);
	if (b == 4 || b == 3)
	{
		var1 = va_arg(ap, long long);
		if (var1 < 0)
			return (ft_get_lld_max(nb, var1));
		ft_nblen(var1, 10, &nb);
		size = nb;
		flag_space(f, nb, t, &nb);
		flag_precision_nb(f, size, t, &nb);
		ft_putnbr_base(var1, 10);
		flag_space_neg(f, nb, t, &nb);
		return (nb);
	}
	var = va_arg(ap, int);
	if (b == 2)
		var = (char)var;
	else if (b == 1)
		var = (short)var;
	ft_nblen(var, 10, &nb);
	size = nb;
	b = flag_plus_space(f, &nb, t, var);
	print_flag_plus_space1(f, t, b, &var);
	flag_space(f, nb, t, &nb);
	print_flag_plus_space(f, t, b, var);
	b = flag_precision_nb(f, size, t, &nb);
	if (!((b == 0 || b == -5) && var == 0))
		ft_putnbr_base(var, 10);
	else
		nb--;
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
