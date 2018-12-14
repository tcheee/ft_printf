/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:00 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 18:56:35 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_string(va_list ap, const char *f, int t)
{
	char	*str;
	int		nb;
	int		size;

	size = -1;
	str = va_arg(ap, char*);
	nb = ft_strlen(str);
	size = flag_precision(f, nb, t);
	if (size > 0)
		nb = size;
	else if (size == -5)
	{
		size = 0;
		nb = size;
	}
	else 
		size = nb;
	flag_space(f, nb, t, &nb);
	ft_nputstr(str, size);
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
