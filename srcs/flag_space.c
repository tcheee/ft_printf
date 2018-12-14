/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:54:04 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 16:43:00 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_space(const char *f, int nb, int t, int *ret)
{
	int		k;
	int		j;
	int		b;
	char	c;

	j = 0;
	c = ' ';
	b = flag_plus_space(f, &nb, t, ret);
	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != '\0') // nein !
		t++;
	if (f[t] == '0')
		c = '0';
	print_flag_plus_space1(b, c);
	k = ft_atoi(&f[t]);
	if (k > 0)
		while (j < k - nb)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
	print_flag_plus_space(b, c);
}
