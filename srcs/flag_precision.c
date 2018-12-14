/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:51:56 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 18:56:22 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// a checker !!!

int		flag_precision(const char *f, int nb, int t)
{
	char	*flag;
	int		k;
	int		size;

	k = 0;
	increment(f, &k);
	if (!(flag = malloc(sizeof(flag) * (k + 1))))
		return (-1);
	k = 0;
	while (f[t] != '.' && f[t] != '\0')
		t++;
	if (f[t] == '\0')
		return (-1);
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

int		flag_precision_nb(const char *f, int nb, int t, int *ret)
{
	char	*flag;
	int		k;
	int		size;

	size = flag_precision(f, nb, t);
	while (size > nb)
	{
		size--;
		ft_putchar('0');
		(*ret)++;
	}
	if (k == 0)
		size = -5;
	return (size);
}
