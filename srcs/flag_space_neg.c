/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:05:11 by ayguillo          #+#    #+#             */
/*   Updated: 2018/12/21 12:07:05 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_space_neg(int space, int nb, int *ret)
{
	int		j;

	j = 0;
	if (space > 0)
	{ 
		while (j < space - nb)
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

