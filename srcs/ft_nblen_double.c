/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 09:28:07 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/03 17:24:04 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		get_neg(long long *nb, int *sum)
{
	if (*nb < 0)
	{
		(*sum)++;
		*nb = -(*nb);
	}
}

void			ft_nblen_double(long long nb, int *sum)
{
	int		x;
	int		i;
	double	y;
	double	tmp;

	i = 0;
	get_neg(&nb, sum);
	x = (unsigned long long)nb;
	ft_nblen(x, 10, sum);
	(*sum)++;
	y = (nb - x);
	tmp = y;
	tmp = tmp * 10;
	while ((int)tmp == 0 && i < 6)
	{
		(*sum)++;
		tmp = tmp * 10;
		i++;
	}
	while (i < 6)
	{
		(*sum)++;
		tmp = tmp * 10;
		i++;
	}
}
