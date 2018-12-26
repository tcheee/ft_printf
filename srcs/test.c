/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 20:47:28 by tcherret         ###   ########.fr       */
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
	y = printf("%05.3d", -42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%05.3d", -42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%03.1d", -10);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%03.1d", -10);
	printf("\nnotre retour: %d\n", y1);
	/*y = printf("%3.4d ", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%3.4d ", 42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%05d ", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%05d ", 42);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%3.d ", 42);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%3.d ", 42);
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
