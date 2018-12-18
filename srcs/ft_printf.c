/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:48:20 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/18 14:24:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		nb;
	int		sum;
	int		b;

	va_start(ap, format);
	i = 0;
	sum = 0;
	b = -5;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if ((nb = dispatcher(ap, i, format)) != -1)
			{
				increment(format, &i);
				sum += nb;
				i++;
				//printf("\n voila le i: %d \n", i);
			}
			else
				increment_error(format, &i, &sum, &b);
		}
		ft_putchar(format[i]);
		if (b > 0)
		{
			flag_space_neg_print_error(b, &sum);
			b = -5;
		}
		sum++;
		i++;
	}
	va_end(ap);
	return (sum);
}
