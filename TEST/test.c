/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/05 14:23:43 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <float.h>

int		main()
{
	char	*str;
	char	*str1;
	double	nb;
	unsigned long long	n;
	int		y;
	int		y1;
	char	a;
	short	b;


	a = -42;
	b = -42;
	str = "test";
	n = 8446744073709551615;
	str1 = "pour comprendre les strings";
	nb = 4054.415641;
	y = printf("%.4d!", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%.4d!", 42);
	printf("\nnotre retour: %d\n", y1);
}
