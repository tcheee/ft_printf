/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:51:56 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 20:41:08 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_precision(const char *f, int t)
{
	char	*flag;
	int		k;
	int		size;

	k = 0;
	increment(f, &k);
	if (!(flag = malloc(sizeof(flag) * (k + 1))))
		return (-1);
	k = 0;
	while (f[t] != '.' && f[t] != 'c' && f[t] != 's' && f[t] != 'p'
			&& f[t] != 'd' && f[t] != 'i' && f[t] != 'o' && f[t] != 'u'
			&& f[t] != 'x' && f[t] != 'X' && f[t] != 'f' && f[t] != '%')
		t++;
	if (f[t] != '.')
		return (-10);
	t++;
	while (f[t] >= '0' && f[t] <= '9')
	{
		flag[k] = f[t];
		k++;
		t++;
	}
	flag[k] = '\0';
	size = ft_atoi(flag);
	free(flag);
	if (k == 0)
		size = -5;
	return (size);
}

void	flag_precision_nb(t_flag flag, int nb, int *ret)
{
	while (flag.precis > nb)
	{
		flag.precis--;
		ft_putchar('0');
		(*ret)++;
	}
}
