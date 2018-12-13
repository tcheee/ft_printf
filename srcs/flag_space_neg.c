/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:05:11 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:42:37 by tcherret         ###   ########.fr       */
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
	while (f[t] != '-') // nein?
		t++;
	k = ft_atoi(&f[t]);
	if (k < 0)
	{ 
		k = -k;
		while (j < k - nb)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
	}
}
