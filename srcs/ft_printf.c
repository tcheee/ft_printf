/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:48:20 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 12:16:57 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		nb;
	int		sum;

	va_start(ap, format);
	i = 0;
	sum = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if ((nb = dispatcher(ap, i, format)) == -1)
				return (-1);
			increment(format, &i);
			i++;
			sum += nb;
		}
		ft_putchar(format[i]);
		sum++;
		i++;
	}
	va_end(ap);
	return (sum); // !on ne compte pas le rajout des espaces via les flags
}
