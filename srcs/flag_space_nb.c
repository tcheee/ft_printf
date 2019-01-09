/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:54:04 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 18:27:25 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_content(char c, int *j, int *ret)
{
	ft_putchar(c);
	(*j)++;
	(*ret)++;
}

static char		get_good_c(t_flag flag, int size)
{
	char c;

	c = ' ';
	if (flag.zero == 1)
		c = '0';
	if (flag.precis != -10)
		if (size >= flag.precis || flag.space > flag.precis)
			c = ' ';
	return (c);
}

void			flag_space_f(t_flag flag, int *ret, int tmpo)
{
	int		j;
	char	c;
	int		size;
	int		tmp;

	size = *ret;
	flag.precis = tmpo;
	tmp = flag.precis;
	j = 0;
	c = ' ';
	if (flag.zero == 1)
		c = '0';
	if (flag.precis <= size)
		flag.precis = 0;
	else
		flag.precis = flag.precis - size;
	if (flag.neg == 0 && flag.sign != 0 && flag.space > tmp && tmp >= 0)
		size++;
	if (flag.neg == 1 && (flag.zero == 1 || flag.sign != 0 || tmp >= size)
			&& flag.space > tmp && tmp >= 0)
		size++;
	if (flag.space > 0)
		while (j < flag.space - size - flag.precis)
			print_content(c, &j, ret);
}

void			flag_space_x(t_flag flag, int *ret)
{
	int		j;
	char	c;
	int		size;
	int		tmp;

	tmp = flag.precis;
	size = *ret;
	j = 0;
	c = get_good_c(flag, size);
	if (flag.precis <= size)
		flag.precis = 0;
	else
		flag.precis = flag.precis - size;
	if (flag.neg == 0)
	{
		if (flag.hash == 1 && tmp >= size)
		{
			size += 2;
			(*ret) = (*ret) + 2;
		}
	}
	if (flag.space > 0)
		while (j < flag.space - size - flag.precis)
			print_content(c, &j, ret);
}

void			flag_space_o(t_flag flag, int *ret)
{
	int		j;
	char	c;
	int		size;

	size = *ret;
	j = 0;
	c = get_good_c(flag, size);
	if (flag.precis <= size)
		flag.precis = 0;
	else
		flag.precis = flag.precis - size;
	if (flag.space > 0)
		while (j < flag.space - size - flag.precis)
			print_content(c, &j, ret);
}
