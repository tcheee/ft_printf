/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:56:48 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/11 17:05:06 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_octal(va_list ap)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ft_putnbr_base(nb, 8);
	return (0);
}
