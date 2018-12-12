/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_the_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:58:21 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 15:07:53 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		capture_the_flag(const char *format, int i)
{
	int	j;
	int	k;
	char *flag;

	j = 0;
	if (!(flag = malloc(sizeof(flag) * 10)))
		return (-1);
	while (format[i] != '\0')
	{
		flag[j] = format[i];
		i++;
		j++;
	}
	flag[j] = '\0';
	ft_putstr(flag);
	return (0);
}
