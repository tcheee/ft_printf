/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:44:41 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/02 17:31:51 by tcherret         ###   ########.fr       */
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
	y = printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24, (short)-2345);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24, (short)-2345);
	printf("\nnotre retour: %d\n", y1);
	y = printf("%-2lu mimi et titi%--14u",(unsigned long)14, 200);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("%-2lu mimi et titi%--14u", (unsigned long)14, 200);
	printf("\nnotre retour: %d\n", y1);
	y = printf("titi%#012o", -874);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("titi%#012o", -874);
	printf("\nnotre retour: %d\n", y1);
	y = printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
	printf("\nnotre retour: %d\n", y1);
	y = printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\nnotre retour: %d\n", y1);
	y = printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1);
	printf("\nretour printf: %d\n", y);
	y1 = ft_printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1);
	printf("\nnotre retour: %d\n", y1);
}
