/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:11:20 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/18 14:00:01 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnstr(char const *str, int size)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
}
