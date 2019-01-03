/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:22:43 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 15:44:20 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_plus_space_percent(const char *f, int t)
{
	int		b;
	int		z;

	z = t;
	b = 0;
	while (f[z] != 'c' && f[z] != 's' && f[z] != 'p'
			&& f[z] != 'd' && f[z] != 'i' && f[z] != 'o'
			&& f[z] != 'u' && f[z] != 'x' && f[z] != 'X'
			&& f[z] != 'f' && f[z] != '\0')
		z++;
	if (f[z] == '\0')
		b = 0;
	return (b);
}

int		flag_plus_space(const char *f, int t)
{
	int		b;
	int		z;

	z = t;
	b = 0;
	while (f[z] != 'c' && f[z] != 's' && f[z] != 'p'
			&& f[z] != 'd' && f[z] != 'i' && f[z] != 'o'
			&& f[z] != 'u' && f[z] != 'x' && f[z] != 'X'
			&& f[z] != 'f' && f[z] != '%' && f[z] != '\0')
	{
		if (f[z] == '+' && b == 3)
			b = 4;
		else if (f[z] == '+' && b != 3)
			b = 1;
		if (f[z] == '-')
			b = 3;
		if (f[z] == ' ' && b == 0)
			b = 2;
		z++;
	}
	if (f[z] == '\0')
		b = 0;
	return (b);
}

void	print_flag_plus_space(t_flag flag, int var, int *ret)
{
	if (flag.zero == 0 && (flag.sign == 1 || flag.sign == 4) && var >= 0)
		ft_putchar('+');
	else if (flag.zero == 1 && (flag.sign == 1 || flag.sign == 4) && var >= 0
			&& flag.precis < flag.space - 1 && flag.precis != -10)
	{
		ft_putchar('+');
		(*ret)++;
	}
	else if (flag.zero == 0 && flag.sign == 2 && var >= 0
			&& (flag.space == 0 || flag.precis != -10))
	{
		ft_putchar(' ');
		(*ret)++;
	}
}

void	print_flag_plus_space1(t_flag flag, int *var, int *ret)
{
	if (flag.zero == 1 && (flag.sign == 1 || flag.sign == 4) && *var >= 0)
	{
		if (flag.precis != -10 && flag.precis < flag.space - 1)
			return ;
		ft_putchar('+');
		(*ret)++;
	}
	if (flag.zero == 0 && (flag.sign == 1 || flag.sign == 4) && *var >= 0)
		(*ret)++;
	if (flag.zero == 1 && flag.sign == 2 && *var >= 0)
	{
		ft_putchar(' ');
		(*ret)++;
	}
	if (flag.zero == 1 && *var < 0)
	{
		if (flag.precis != -10)
			if (*ret >= flag.precis || flag.space > flag.precis)
				return ;
		ft_putchar('-');
		*var = -(*var);
	}
}
