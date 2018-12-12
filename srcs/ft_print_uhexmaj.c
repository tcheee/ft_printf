/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhexX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:06:22 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/11 17:36:25 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_uhexmaj(va_list ap)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ft_putnbr_basemaj(nb, 16);
	return (0);
}
