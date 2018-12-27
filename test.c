/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/27 16:49:01 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "new_ft_printf/includes/ft_printf.h"

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
	/*y = printf("%o, %ho, %hho", -42, -42, -42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%o, %ho, %hho", -42, -42, -42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%hho", a);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%hho", a);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%ho", b);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%ho", b);
	printf("\nnotre retour: %d\n", y1);*/
	y = printf("{%-15p}", 0);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("{%-15p}", 0);
	printf("\nnotre retour: %d\n", y1);
	y = printf("{% 03d}", 0);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("{% 03d}", 0);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%.10p", 0);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%.10p", 0);
	printf("\nnotre retour: %d\n", y1);
	/*y = printf("{%05.c}", 0);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("{%05.c}", 0);
	printf("\nnotre retour: %d\n", y1);
	/*y = printf("%+010d ", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%+010d ", 42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%d ", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%d ", 42);
	printf("\nnotre retour: %d\n", y1);*/
}
