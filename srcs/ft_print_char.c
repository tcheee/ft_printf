/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:18:03 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 20:11:07 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list ap, t_flag flag)
{
	char	var;
	int		nb;

	nb = 1;
	var = va_arg(ap, int);
	if (flag.sign != 3)
		flag_space_str(flag, &nb);
	ft_putchar(var);
	var = (char)var;
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
