/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 20:15:52 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int		main()
{
	char	*str;
	char	*str1;
	double	nb;
	int		y;
	int		y1;


	//ft_putnbr(ft_atoi("10"));
	str = "test";
	str1 = "pour comprendre les strings";
	nb = 4.1274;
	y = printf("1: test %.4f !\n", nb);
	ft_putnbr(y);
	ft_putchar('\n');
	y1 = ft_printf("2: test %.4f !\n", nb);
	ft_putnbr(y1);
	//ft_nputstr(str1, 2);
	//ft_putchar('\n');
}
