/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:15:37 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/27 15:24:05 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		precis0_varneg(long long *var, t_flag flag, int *nb)
{
	if (flag.space != 0)
		(*nb)++;
	ft_putchar('-');
	*var = -(*var);
}

int		ft_get_lld_min(int nb, long long var1)
{
	unsigned long long n;

	n = -var1;
	ft_putchar('-');
	nb++;
	ft_putnbr_unsign(n, 10);
	ft_nblen_unsign(n, 10, &nb);
	return (nb);
}

static int		print_long(va_list ap, int nb, t_flag flag)
{
	long long	var1;
	int			size;

	var1 = va_arg(ap, long long);
	if (var1 < 0)
		return (ft_get_lld_min(nb, var1));
	ft_nblen(var1, 10, &nb);
	size = nb;
	print_flag_plus_space1_uns(flag.sign, flag.zero,
			(unsigned long long*)&var1, (unsigned long long*)&nb);
	if (flag.sign != 3 || flag.precis )
		flag_space(flag, &nb);
	print_flag_plus_space_uns(flag.sign, flag.zero, (unsigned long long*)&var1);
	if (flag.precis >= 0 && var1 < 0)
		precis0_varneg((long long *)&var1, flag, &nb);
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var1 == 0))
		ft_putnbr_base(var1, 10);
	else
		nb--;
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}

// print_numbr "bon", a implementer sur les autres print"figures", possibilité de simplifier en prenant ensemble des cas, a checker"

int		ft_print_number(va_list ap, t_flag flag)
{
	int	var;
	int	nb;
	int size;
	char	a;

	nb = 0;
	a = 0;
	if (flag.hl == 4 || flag.hl == 3)
		return (print_long(ap, nb, flag));
	var = va_arg(ap, int);
	if (flag.hl == 2)
		var = (char)var;
	else if (flag.hl == 1)
		var = (short)var;
	if (!(var == 0 && flag.precis == -5) && !(var == 0 && flag.precis == 0))
		ft_nblen(var, 10, &nb);
	if (var < 0)
		flag.neg = 1;
	size = nb;
	if (var < 0 && flag.precis != -10)
	{
		size--;
		a = 1;
	}
	print_flag_plus_space1(flag, &var, &nb);
	if (flag.precis >= 0 && var < 0 && flag.space == 0)
		nb++;
	if (flag.sign != 3 && flag.sign != 4)
		flag_space(flag, &nb);
	print_flag_plus_space(flag, var, &nb);
	if (flag.precis >= 0 && var < 0)
		precis0_varneg((long long *)&var, flag, &nb);
	if (a == 1)
		nb--;
	flag_precision_nb(flag, size, &nb);
	if (!((flag.precis == 0 || flag.precis == -5) && var == 0))
		ft_putnbr_base(var, 10);
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
