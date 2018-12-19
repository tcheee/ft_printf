/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 17:38:16 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int		main()
{
	char	*str;
	char	*str1;
	double	nb;
	long long	n;
	int		y;
	int		y1;


	str = "test";
	n = 415416541;
	str1 = "pour comprendre les strings";
	nb = 4.1;
	/*y = printf("%   +      d", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%  +     d", 42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("% d", -42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("% d", -42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("% +d", -42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("% +d", -42);
	printf("\nnotre retour: %d\n", y1);*/
	y = printf("test %#.o test", 0);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("test %#.o test", 0);
	printf("\nnotre retour: %d\n", y1);
	/*y = printf("%0++ ++5d ", -42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%0++ ++5d ", -42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%+010d ", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%+010d ", 42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%d ", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%d ", 42);
	printf("\nnotre retour: %d\n", y1);*/
}
