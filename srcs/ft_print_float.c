/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:23:41 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 20:28:48 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_cas_0(t_flag flag, long double var, int *nb, int tmpo)
{
	int tmp;

	if (flag.sign == 1 && var > 0)
		nb++;
	tmp = 0;
	ft_nblen((long long)var, 10, &tmp);
	*nb = (flag.hash == 1 &&
			(flag.precis == 0 || flag.precis == -5)) ? *nb + 1 : *nb;
	if (flag.sign == 1 && var > 0 && flag.zero == 1)
		ft_putchar('+');
	if (flag.sign != 3 && flag.sign != 4)
		flag_space_f(flag, nb, tmpo);
	if (flag.sign == 1 && var > 0 && flag.zero == 0)
		ft_putchar('+');
	nb = nb - 7;
	if (var < 0)
	{
		ft_putchar('-');
		var = -var;
	}
	if ((int)(var * 10) % 10 >= 5)
		var++;
	ft_putnbr_base((long long)var, 10);
}

static void		print_cas_1(t_flag flag, double var, int *nb, int tmpo)
{
	int tmp;

	tmp = flag.precis + 1;
	ft_nblen((long long)var, 10, &tmp);
	if (var < 0 && flag.zero == 1)
	{
		ft_putchar('-');
		var = -var;
	}
	if (flag.sign == 1 && var > 0 && flag.zero == 1)
		ft_putchar('+');
	if (flag.sign != 3 && flag.sign != 4)
		flag_space_f(flag, &tmp, tmpo);
	if (flag.sign == 1 && var > 0 && flag.zero == 0)
		ft_putchar('+');
	if (flag.sign == 1 && var > 0)
		tmp++;
	if (var < 0 && flag.zero == 0)
	{
		ft_putchar('-');
		var = -var;
	}
	ft_putnbr_double(var, flag.precis);
	*nb = tmp++;
}

static void		print_cas_2(t_flag flag, long double var, int *nb, int tmpo)
{
	int tmp;

	tmp = flag.precis + 1;
	ft_nblen((long long)var, 10, &tmp);
	if (var < 0 && flag.zero == 1)
	{
		ft_putchar('-');
		var = -var;
	}
	if (flag.sign == 1 && var > 0 && flag.zero == 1)
		ft_putchar('+');
	if (flag.sign != 3 && flag.sign != 4)
		flag_space_f(flag, &tmp, tmpo);
	if (flag.sign == 1 && var > 0 && flag.zero == 0)
		ft_putchar('+');
	if (flag.sign == 1 && var > 0)
		tmp++;
	if (var < 0 && flag.zero == 0)
	{
		ft_putchar('-');
		var = -var;
	}
	ft_putnbr_long_double(var, flag.precis);
	*nb = tmp++;
}

static int		ft_print_long_float(va_list ap, t_flag flag)
{
	long double		var;
	int				nb;
	int				tmpo;

	nb = 0;
	tmpo = flag.precis;
	var = va_arg(ap, long double);
	ft_nblen_double(var, &nb);
	if (flag.precis == -10)
		flag.precis = 6;
	if (flag.precis > 0)
		nb -= (flag.precis);
	if (flag.precis <= 0 && flag.precis != -10)
		print_cas_0(flag, var, &nb, tmpo);
	else
		print_cas_2(flag, var, &nb, tmpo);
	if ((flag.precis == 0 || flag.precis == -5) && flag.hash == 1)
		flag_hashf(flag);
	return (ender(flag, &nb));
}

int				ft_print_float(va_list ap, t_flag flag)
{
	double	var;
	int		nb;
	int		tmpo;

	nb = 0;
	tmpo = flag.precis;
	if (flag.hl == 5)
		return (ft_print_long_float(ap, flag));
	var = va_arg(ap, double);
	if (!(flag.precis == -5 || flag.precis == 0))
		ft_nblen_double(var, &nb);
	else
		ft_nblen((long long)var, 10, &nb);
	if (flag.precis == -10)
		flag.precis = 6;
	if (flag.precis > 0)
		nb -= (flag.precis);
	if (flag.precis <= 0 && flag.precis != -10)
		print_cas_0(flag, var, &nb, tmpo);
	else
		print_cas_1(flag, var, &nb, tmpo);
	if ((flag.precis == 0 || flag.precis == -5) && flag.hash == 1)
		flag_hashf(flag);
	return (ender(flag, &nb));
}
