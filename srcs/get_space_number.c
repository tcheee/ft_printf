/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 11:41:56 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 20:02:06 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_space_after_hash(const char *f, int t, int k)
{
	int k1;

	while (f[t] != '#' && f[t] != '\0')
	{
		if (!(f[t] >= '0' && f[t] <= '9'))
			break ;
		t++;
	}
	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != 'c' && f[t] != 's' && f[t] != 'p'
			&& f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X'
			&& f[t] != 'f' && f[t] != '%' && f[t] != '\0' && f[t] != '.')
		t++;
	while (f[t] == '0')
		t++;
	while (f[t] == '+' || f[t] == ' ')
		t++;
	k1 = ft_atoi(&f[t]);
	if (k1 == 0)
		k1 = k;
	return (k1);
}

int				get_space_number(const char *f, int t, t_flag flag)
{
	int		k;

	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != 'c' && f[t] != 's' && f[t] != 'p'
			&& f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X'
			&& f[t] != 'f' && f[t] != '%' && f[t] != '\0' && f[t] != '.')
		t++;
	while (f[t] == '0')
		t++;
	while (f[t] == '+' || f[t] == ' ')
		t++;
	k = ft_atoi(&f[t]);
	if (flag.hash == 1)
		k = get_space_after_hash(f, t, k);
	return (k);
}
