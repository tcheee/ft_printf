/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:07:39 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/18 14:50:04 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		dispatcher(va_list ap, int i, const char *f)
{
	int t;

	if (f[i] == '\0')
		return (-1);
	t = i;
	if (check_error(f, i) == -1)
		return (-1);
	increment(f, &i);
	if (f[i] == 'c')
		return (ft_print_char(ap, f, t));
	else if (f[i] == 's')
		return (ft_print_string(ap, f, t));
	else if (f[i] == 'p')
		return (ft_print_hex(ap, f, t));
	else if (f[i] == 'd' || f[i] == 'i')
		return (ft_print_number(ap, f, t));
	else if (f[i] == 'o')
		return (ft_print_octal(ap, f, i, t));
	else if (f[i] == 'u')
		return (ft_print_unsign(ap, f, i, t));
	else if (f[i] == 'x')
		return (ft_print_uhex(ap, f, i, t));
	else if (f[i] == 'X')
		return (ft_print_uhexmaj(ap, f, i, t));
	else if (f[i] == 'f')
		return (ft_print_float(ap, f, i, t));
	else if (f[i] == '%')
		return (ft_print_percent(f, t));
	return (-1);
}
