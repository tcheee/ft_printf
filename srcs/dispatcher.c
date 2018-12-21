/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:07:39 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 14:16:11 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		dispatcher(va_list ap, int i, const char *f)
{
	int t;
	t_flag flag;

	t = i;
	capture_the_flag(f, t, &flag);
	if (f[i] == '\0')
		return (-1);
	if (check_error(f, i) == -1)
		return (-1);
	increment(f, &i);
	if (f[i] == 'c')
		return (ft_print_char(ap, flag));
	else if (f[i] == 's')
		return (ft_print_string(ap, flag));
	else if (f[i] == 'p')
		return (ft_print_hex(flag, ap));
	if (f[i] == 'd' || f[i] == 'i')
		return (ft_print_number(ap, flag));
	else if (f[i] == 'o')
		return (ft_print_octal(ap, flag));
	else if (f[i] == 'u')
		return (ft_print_unsign(ap, flag));
	else if (f[i] == 'x')
		return (ft_print_uhex(ap, flag));
	else if (f[i] == 'X')
		return (ft_print_uhexmaj(ap, flag));
	else if (f[i] == 'f')
		return (ft_print_float(ap, f, t, flag));
	else if (f[i] == '%')
		return (ft_print_percent(flag, f, t));
	return (-1);
}
