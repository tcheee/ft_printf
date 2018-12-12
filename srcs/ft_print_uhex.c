/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:05:47 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/11 17:36:39 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_uhex(va_list ap)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ft_putnbr_base(nb, 16);
	return (0);
}
