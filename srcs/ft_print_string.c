/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:00 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/18 17:25:58 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_print_string(va_list ap, const char *f, int t)
{
	char	*str;
	int		nb;
	int		size;

	size = -1;
	str = va_arg(ap, char*);
	if (str && str[0] != '\0')
		nb = ft_strlen(str);
	else
		nb = 0;
	size = flag_precision(f, t);
	if (size > 0 && nb != 0)
		nb = size;
	else if (size == -5)
	{
		size = 0;
		nb = size;
	}
	else 
		size = nb;
	flag_space(f, nb, t, &nb);
	if (str != NULL)
		ft_putnstr(str, size);
	else
	{
		nb = 6;
		ft_putstr("(null)");
	}
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
