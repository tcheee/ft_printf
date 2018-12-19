/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:22:43 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 16:59:02 by tcherret         ###   ########.fr       */
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

int		flag_plus_space(const char *f, int *nb, int t, int var)
{
	int		b;
	int		z;
	int		u;

	z = t;
	b = 0;
	u = 0;
	while (f[z] != 'c' && f[z] != 's' && f[z] != 'p'
			&& f[z] != 'd' && f[z] != 'i' && f[z] != 'o'
			&& f[z] != 'u' && f[z] != 'x' && f[z] != 'X'
			&& f[z] != 'f' && f[z] != '%' && f[z] != '\0')
	{
		if (f[z] == '+' && var >= 0)
		{
			if (b == 2)
				(*nb)--;
			b = 1;
			if (u == 0)
			{
				(*nb)++;
				u = 1;
			}
		}
		if (f[z] == ' ' && b == 0)
		{
			b = 2;
			if (var >= 0)
				(*nb)++;
		}
		z++;
	}
	if (f[z] == '\0')
	{
		b = 0;
		(*nb)--;
	}
	return (b);
}

void	print_flag_plus_space(const char *f, int t, int b, int var)
{
	int c;

	c= ' ';
	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != '\0') // nein !
	{
		if (f[t] == '-')
			break ;
		if (f[t] == '.')
			break ;
		t++;
	}
	if (f[t] == '0')
		c = '0';
	if (c == ' ' && b == 1 && var >= 0)
		ft_putchar('+');
	else if (c == ' ' && b == 2 && var >= 0)
		ft_putchar(' ');
}

void	print_flag_plus_space1(const char *f, int t, int b, int *var)
{
	int c;

	c = ' ';

	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != '\0') // nein !
	{
		if (f[t] == '-')
			break ;
		if (f[t] == '.')
			break ;
		t++;
	}
	if (f[t] == '0')
		c = '0';
	if (c == '0' && b == 1 && *var > 0)
		ft_putchar('+');
	if (c == '0' && *var < 0)
	{
		ft_putchar('-');
		*var = -(*var);
	}
}
