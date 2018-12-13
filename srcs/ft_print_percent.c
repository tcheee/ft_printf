/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:35:39 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:21:41 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_percent(const char *f, int t)
{
	int nb;

	nb = 1;
	flag_space(f, nb, t, &nb);
	ft_putchar('%');
	flag_space_neg(f, nb, t, &nb);
	return (nb);
}
