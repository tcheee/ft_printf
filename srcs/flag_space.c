/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:54:04 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 18:53:22 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_space_percent(const char *f, int nb, int t, int *ret)
{
	int		k;
	int		j;
	int		b;
	char	c;

	j = 0;
	c = ' ';
	b = flag_plus_space_percent(f, t);
	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != '\0') // nein !
	{
		if (f[t] == '-')
			break ;
		if (f[t] == '.')
			break ;
		t++;
	}
	if (f[t] == '0')
		c = '0';
	k = ft_atoi(&f[t]);
	if (k > 0)
		while (j < k - nb)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
}

void	flag_space_o(const char *f, int nb, int t, int *ret)
{
	int		k;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != '\0') // nein !
	{
		if (f[t] == '#')
			nb++;
		if (f[t] == '-')
			break ;
		if (f[t] == '.')
			break ;
		t++;
	}
	if (f[t] == '0')
		c = '0';
	k = ft_atoi(&f[t]);
	if (k > 0)
		while (j < k - nb)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
}

int		flag_space_x(const char *f, int nb, int t, int *ret)
{
	int		k;
	int		j;
	char	c;
	int		i;
	int		b;

	j = 0;
	c = ' ';
	i = t;
	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != '\0') // nein !
	{
		if (f[t] == '#')
		{
			nb = nb + 2;
			b = -2;
		}
		if (f[t] == '-')
			break ;
		if (f[t] == '.')
			break ;
		t++;
	}
	if (f[t] == '0')
	{
		c = '0';
		if (b == -2)
		{
			flag_hashx(f, i, ret);
			b = -1;
		}
	}
	k = ft_atoi(&f[t]);
	if (k > 0)
		while (j < k - nb)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
	return (b);
}

void	flag_space(const char *f, int nb, int t, int *ret)
{
	int		k;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	while (f[t] != '0' && f[t] != '1' && f[t] != '2'
			&& f[t] != '3' && f[t] != '4' && f[t] != '5'
			&& f[t] != '6' && f[t] != '7' && f[t] != '8'
			&& f[t] != '9' && f[t] != '\0') // nein !
	{
		if (f[t] == '#')
			nb = nb + 2;
		if (f[t] == '-')
			break ;
		if (f[t] == '.')
			break ;
		t++;
	}
	if (f[t] == '0')
	{
		c = '0';
		t++;
	}
	while (f[t] == '+' || f[t] == ' ')
		t++;
	k = ft_atoi(&f[t]);
	if (k > 0)
		while (j < k - nb)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
}
