/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:18:03 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:51:15 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list ap, const char *f, int t)
{
	char	var;
	int		nb;

	nb = 1;
	var = va_arg(ap, int);
	flag_space(f, nb, t, &nb);
	ft_putchar(var);
	flag_space_neg(f, nb, t, &nb);
	var = (char)var;
	return (nb);
}
