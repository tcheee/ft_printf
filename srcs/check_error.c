/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:22:53 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 20:35:27 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		check_error1(const char *f, int j, int *b)
{
	while (f[j] != 'c' && f[j] != 's' && f[j] != 'p'
			&& f[j] != 'd' && f[j] != 'i' && f[j] != 'o'
			&& f[j] != 'u' && f[j] != 'x' && f[j] != 'X'
			&& f[j] != 'f' && f[j] != '%' && f[j] != '\0')
	{
		if (f[j] != '.' && f[j] != '+' && f[j] != '-' && f[j] != '#'
				&& f[j] != ' ' && f[j] != 'l' && f[j] != 'L' && f[j] != 'h'
				&& !(f[j] >= '0' && f[j] <= '9'))
			*b = -1;
		j++;
	}
}

int				check_error(const char *f, int i)
{
	int	j;
	int	b;

	j = i;
	b = 1;
	if (f[j] == 'c' || f[j] == 's' || f[j] == 'p'
			|| f[j] == 'd' || f[j] == 'i' || f[j] == 'o'
			|| f[j] == 'u' || f[j] == 'x' || f[j] == 'X' || f[j] == 'L'
			|| f[j] == 'f' || f[j] == '%' || f[j] == 'l' || f[j] == 'h')
	{
		while (f[j] == 'c' || f[j] == 's' || f[j] == 'p'
				|| f[j] == 'd' || f[j] == 'i' || f[j] == 'o'
				|| f[j] == 'u' || f[j] == 'x' || f[j] == 'X' || f[j] == 'L'
				|| f[j] == 'f' || f[j] == '%' || f[j] == 'l' || f[j] == 'h')
			j++;
	}
	else
		check_error1(f, j, &b);
	return (b);
}
