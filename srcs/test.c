/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 15:53:55 by tcherret         ###   ########.fr       */
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


	str = "test %s\n";
	n = 415416541;
	str1 = "pour comprendre les strings";
	nb = 4.1;
	/* ACHECKERRRRR
	y = printf("%010.3d", -1);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%010.3d", -1);
	printf("\nnotre retour: %d\n", y1);*/
	y = printf("%lu", -1);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%lu", -1);
	printf("\nnotre retour: %d\n", y1);
	/*y = printf("% +d", -42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("% +d", -42);
	printf("\nnotre retour: %d\n", y1);
	y = printf(str, str1);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("test %s\n", str1);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%0++ ++5d ", -42);
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
