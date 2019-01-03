/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 15:27:55 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int		main()
{
	char	*str;
	char	*str1;
	double	nb;
	long long	n;
	int		y;
	int		y1;
	char	a;
	short	b;


	a = -42;
	b = -42;
	str = "test";
	n = 415416541;
	str1 = "pour comprendre les strings";
	nb = 4.1;
	y = printf("cc%#0012x !!", 0xe);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("cc%#0012x !!", 0xe);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%#010.2x", 12345);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%#010.2x", 12345);
	printf("\nnotre retour: %d\n", y1);
}
