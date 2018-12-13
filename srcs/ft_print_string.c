/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:00 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:21:38 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_string(va_list ap, const char *f, int t)
{
	char	*str;
	int		nb;

	str = va_arg(ap, char*);
	nb = ft_strlen(str);
	flag_space(f, nb, t, &nb);
	ft_putstr(str);
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
