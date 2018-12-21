/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:54:04 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 14:08:00 by ayguillo         ###   ########.fr       */
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

void	flag_space_o(t_flag flag, int *ret)
{
	int		j;
	char	c;
	int		size;

	size = *ret;
	j = 0;
	c = ' ';
	if (flag.hash == 1)
		(*ret)++;
	if (flag.zero == 1)
		c = '0';
	if (flag.precis <= size)
		flag.precis = 0;
	else
		flag.precis = flag.precis - size;
	if (flag.space > 0)
		while (j < flag.space - size - flag.precis)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
}

void	flag_space(int space, int precis, int zero, int *ret)
{
	int		j;
	char	c;
	int		size;

	size = *ret;
	j = 0;
	c = ' ';
	if (zero == 1)
		c = '0';
	if (precis <= size)
		precis = 0;
	else
		precis = precis - size;
	if (space > 0)
		while (j < space - size - precis)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
}
