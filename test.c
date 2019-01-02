/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/02 19:32:47 by tcherret         ###   ########.fr       */
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
	y = printf("%#.o", 042);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%#.o", 042);
	printf("\nnotre retour: %d\n", y1);
	y = printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\nnotre retour: %d\n", y1);
}
