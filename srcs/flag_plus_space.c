/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:22:43 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/20 18:54:39 by tcherret         ###   ########.fr       */
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
		if (f[z] == '+' && b != 3)
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

void	print_flag_plus_space(int sign, int zero, int var, int *ret)
{
	if (zero == 0 && sign == 1)
	{
		ft_putchar('+');
		(*ret)++;
	}
	else if (zero == 0 && sign == 2 && var >= 0)
	{
		ft_putchar(' ');
		(*ret)++;
	}
}

void	print_flag_plus_space1(int sign, int zero, int *var, int *ret)
{
	if (zero == 1 && sign == 1 && *var > 0)
	{
		ft_putchar('+');
		(*ret)++;
	}
	if (zero == 1 && sign == 1 && *var < 0)
	{
		ft_putchar('-');
		(*ret)++;
		*var = -(*var);
	}
}
