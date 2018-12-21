/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:15:37 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 13:36:45 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		precis0_varneg(int *var, int *nb)
{
		ft_putchar('-');
		(*nb)++;
		*var = -(*var);
}

/*int		ft_get_lld_min(int nb, long long var1)
{
	unsigned long long n;

	n = -var1;
	ft_putchar('-');
	nb++;
	ft_putnbr_unsign(n, 10);
	ft_nblen_unsign(n, 10, &nb);
	//  a faire: gerer les espaces et les precision & co
	return (nb);
}*/

/*int		print_long(va_list ap, const char *f, int nb, t_flag flag)
{
	long long	var1;
	int			size;

	var1 = va_arg(ap, long long);
	if (var1 < 0)
		return (ft_get_lld_min(nb, var1));
	ft_nblen(var1, 10, &nb);
	size = nb;
	print_flag_plus_space1(flag.sign, flag.zero, &var1);
	if (flag.sign != 3 || flag.precis )
		flag_space(flag.space, nb, flag.zero, &nb);
	print_flag_plus_space(flag.sign, flag.zero, var1);
	if (flag.precis >= 0 && var1 < 0)
		precis0_varneg(&var1), &nb);
	flag_precision_nb(flag.precis, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_base(var1, 10);
	else
		nb--;
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}*/

int		ft_print_number(va_list ap, t_flag flag)
{
	int	var;
	int	nb;
	int size;

	nb = 0;
	//if (flag.hl == 4 || flag.hl == 3)
		//return (print_long(ap, f, nb, flag));
	var = va_arg(ap, int);
	if (flag.hl == 2)
		var = (char)var;
	else if (flag.hl == 1)
		var = (short)var;
	ft_nblen(var, 10, &nb);
	size = nb;
	print_flag_plus_space1(flag.sign, flag.zero, &var, &nb);
	if (flag.sign != 3)
		flag_space(flag.space, flag.precis, flag.zero, &nb);
	print_flag_plus_space(flag.sign, flag.zero, var, &nb);
	if (flag.precis >= 0 && var < 0)
		precis0_varneg(&var, &nb);
	flag_precision_nb(flag.precis, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_base(var, 10);
	else
		nb--;
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
