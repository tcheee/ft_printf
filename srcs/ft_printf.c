/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:48:20 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 20:39:11 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		starter(int *i, int *sum, int *b)
{
	*i = 0;
	*sum = 0;
	*b = -5;
}

static void		increase_nb(const char *format, int *i, int *sum, int nb)
{
	increment(format, i);
	(*sum) += nb;
	(*i)++;
}

static void		get_cont(const char *format, int *i, int *sum)
{
	ft_putchar(format[*i]);
	(*sum)++;
	(*i)++;
}

static void		get_b_neg(int *b, int *sum)
{
	flag_space_neg_print_error(*b, sum);
	*b = -5;
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		nb;
	int		sum;
	int		b;

	va_start(ap, format);
	starter(&i, &sum, &b);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if ((nb = dispatcher(ap, i, format)) != -1)
				increase_nb(format, &i, &sum, nb);
			else
				increment_error(format, &i, &b);
		}
		else
			get_cont(format, &i, &sum);
		if (b > 0)
			get_b_neg(&b, &sum);
	}
	va_end(ap);
	return (sum);
}
