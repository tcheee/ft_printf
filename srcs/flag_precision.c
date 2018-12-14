/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:51:56 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 16:21:34 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// a checker !!!

int		flag_precision(const char *f, int nb, int t, int *ret)
{
	char	*flag;
	int		k;
	int		size;

	k = 0;
	while (f[t] != '.')
		t++;
	while (f[t] == '.')
		t++;
	t++;
	while (f[t] >= '0' && f[t] <= '9')
	{
		flag[k] = f[t];
		k++;
		t++;
	}
	size = ft_atoi(flag);
	return (size);
}
