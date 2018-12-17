/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:11:49 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/17 17:15:00 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_nblen_unsign(unsigned long long nb, int base, int *ret)
{
	if (nb < (unsigned long long)base)
	{
		if (nb < 10)
			(*ret)++;
		else
			(*ret)++;
		return ;
	}
	ft_nblen_unsign(nb / base, base, ret);
	ft_nblen_unsign(nb % base, base, ret);
}
