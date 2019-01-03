/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:05:11 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/03 15:48:23 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_space_neg(int space, int precis, int *ret)
{
	int		j;
	int		size;

	size = *ret;
	if (space < 0)
		space = -space;
	j = 0;
	if (precis < size)
		precis = 0;
	else
		precis = precis - size;
	if (space > 0)
	{
		while (j < space - size - precis)
		{
			ft_putchar(' ');
			j++;
			(*ret)++;
		}
	}
}

int		flag_space_neg_nb_error(const char *f, int t)
{
	int		k;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	while (f[t] != '-' && f[t] != '\0')
		t++;
	k = ft_atoi(&f[t]);
	return (k);
}

void	flag_space_neg_print_error(int b, int *sum)
{
	while (b - 1)
	{
		ft_putchar(' ');
		(*sum)++;
		b--;
	}
}
