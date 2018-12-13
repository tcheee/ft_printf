/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:50:54 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 17:57:37 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_nblen(unsigned long long nb, int base, int *sum)
{
	if (nb < base)
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
