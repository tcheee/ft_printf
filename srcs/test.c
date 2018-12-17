/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/17 18:25:05 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int		main()
{
	char	*str;
	char	*str1;
	double	nb;
	unsigned long long n;
	int		y;
	int		y1;


	//ft_putnbr(ft_atoi("10"));
	str = "test";
	n = 1844674407370955161;
	str1 = "pour comprendre les strings";
	nb = 4.1;
	y = printf("1: test %wlld !!!\n", n);
	ft_putnbr(y);
	ft_putchar('\n');
	y1 = ft_printf("2: test %wwwwwwwwwwwwlld !!!\n", n);
	ft_putnbr(y1);
}
