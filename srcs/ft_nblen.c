/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:50:54 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 19:59:34 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_nblen(long long nb, int base, int *sum)
{
	if (nb < 0)
	{
		nb = -nb;
		(*sum)++;
	}
	if (nb < (long long)base)
	{
		if (nb < 10)
			(*sum)++;
		else
			(*sum)++;
		return ;
	}
	ft_nblen(nb / base, base, sum);
	ft_nblen(nb % base, base, sum);
}
