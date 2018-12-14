/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:27:24 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 19:47:02 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_hashxmaj(const char *f, int t, int *ret)
{
	int b;

	b = 0;
	while (f[t] != '\0')
	{
		if (f[t] == '#')
			b = 1;
		t++;
	}
	if (b == 1)
	{
		ft_putstr("0X");
		*ret = *ret + 2;
	}
}

void	flag_hashx(const char *f, int t, int *ret)
{
	int b;

	b = 0;
	while (f[t] != '\0')
	{
		if (f[t] == '#')
			b = 1;
		t++;
	}
	if (b == 1)
	{
		ft_putstr("0x");
		*ret = *ret + 2;
	}
}

void	flag_hasho(const char *f, int t, int *ret)
{
	int b;

	b = 0;
	while (f[t] != '\0')
	{
		if (f[t] == '#')
			b = 1;
		t++;
	}
	if (b == 1)
	{
		ft_putstr("0");
		(*ret)++;
	}
}

//void	flag_hashfloat(const char)
