/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 14:40:27 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int		main()
{
	char *str;
	char *str1;
	int		nb;
	int y;
	int y1;


	str = "test";
	str1 = "pour comprendre les strings";
	nb = 42000;
	y = printf("test %10d !\n", nb);
	ft_putnbr(y);
	ft_putchar('\n');
	y1 = ft_printf("test %10d !\n", nb);
	ft_putnbr(y1);
	//ft_putchar('\n');
}
