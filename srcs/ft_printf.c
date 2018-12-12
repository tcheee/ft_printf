/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:48:20 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 15:16:42 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		nb;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if ((nb = dispatcher(ap, i, format)) == -1)
			{
				ft_putstr("error");
				return (-1);
			}
			increment(format, &i);
			i++;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (nb);
}
