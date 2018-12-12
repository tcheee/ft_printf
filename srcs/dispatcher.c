/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:07:39 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 15:19:17 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		dispatcher(va_list ap, int i, const char *f)
{
	//capture_the_flag(f, i);
	increment(f, &i);
	if (f[i] == 'c')
		return (ft_print_char(ap));
	else if (f[i] == 's')
		return (ft_print_string(ap));
	else if (f[i] == 'p')
		return (ft_print_hex(ap));
	else if (f[i] == 'd' || f[i] == 'i')
		return (ft_print_number(ap, f, i));
	else if (f[i] == 'o')
		return (ft_print_octal(ap));
	else if (f[i] == 'u')
		return (ft_print_unsign(ap));
	else if (f[i] == 'x')
		return (ft_print_uhex(ap));
	else if (f[i] == 'X')
		return (ft_print_uhexmaj(ap));
	else if (f[i] == 'f')
		return (ft_print_float(ap, f, i));
	else if (f[i] == '%')
		return (ft_print_percent());
	return (-1);
}
