/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:05:11 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 17:13:34 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_space_neg(const char *f, int nb, int t, int *ret)
{
	int		k;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	while (f[t] != '-' && f[t] != '\0')
		t++;
	while (f[t] == '-' || f[t] == '+' || f[t] == '#')
		t++;
	k = ft_atoi(&f[t]);
	if (k > 0)
	{ 
		while (j < k - nb)
		{
			ft_putchar(c);
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

