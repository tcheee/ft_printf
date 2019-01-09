/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:27:24 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 17:59:25 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_hash(const char *f, int t)
{
	int b;

	b = 0;
	while (f[t] != 'c' && f[t] != 's' && f[t] != 'p'
			&& f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X'
			&& f[t] != 'f' && f[t] != '%' && f[t] != '\0')
	{
		if (f[t] == '#')
			b = 1;
		t++;
	}
	return (b);
}

void	flag_hashxmaj(t_flag flag)
{
	if (flag.hash == 1)
		ft_putstr("0X");
}

void	flag_hashx(t_flag flag)
{
	if (flag.hash == 1)
		ft_putstr("0x");
}

void	flag_hasho(t_flag flag)
{
	if (flag.hash == 1)
		ft_putstr("0");
}

void	flag_hashf(t_flag flag)
{
	if (flag.hash == 1)
		ft_putchar('.');
}
