/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:22:43 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/18 18:19:04 by tcherret         ###   ########.fr       */
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

int		flag_plus_space(const char *f, int *nb, int t, int *ret)
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
		if (f[z] == '+' && b == 0)
		{
			b = 1;
			(*nb)++;
			(*ret)++;
		}
		if (f[z] == ' ' && b == 0)
		{
			b = 2;
			(*nb)++;
			(*ret)++;
		}
		z++;
	}
	if (f[z] == '\0')
	{
		b = 0;
		(*ret)--;
	}
	return (b);
}

void	print_flag_plus_space(int b, char c)
{
	if (b == 1 && c != '0')
		ft_putchar('+');
	if (b == 2)
		ft_putchar(' ');
}

void	print_flag_plus_space1(int b, char c)
{
	if (c == '0' && b == 1)
		ft_putchar('+');
}
