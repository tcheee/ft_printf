/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:51:56 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/04 19:55:36 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ending(char *flag, int k, int *size)
{
	flag[k] = '\0';
	*size = ft_atoi(flag);
	if (k == 0)
		*size = -5;
	free(flag);
}

static void		gain_space(const char *f, char **flag, int *t, int *k)
{
	while (f[*t] >= '0' && f[*t] <= '9')
	{
		(*flag)[*k] = f[*t];
		(*k)++;
		(*t)++;
	}
}

int				flag_precision(const char *f, int t)
{
	char	*flag;
	int		k;
	int		size;

	k = 0;
	increment(f, &k);
	if (!(flag = (char*)malloc(sizeof(*flag) * (k + 1))))
		return (-1);
	k = 0;
	while (f[t] != '.' && f[t] != 'c' && f[t] != 's' && f[t] != 'p'
			&& f[t] != 'd' && f[t] != 'i' && f[t] != 'o' && f[t] != 'u'
			&& f[t] != 'x' && f[t] != 'X' && f[t] != 'f' && f[t] != '%')
		t++;
	if (f[t] != '.')
	{
		free(flag);
		return (-10);
	}
	t++;
	gain_space(f, &flag, &t, &k);
	ending(flag, k, &size);
	return (size);
}

void			flag_precision_nb(t_flag flag, int nb, int *ret)
{
	while (flag.precis > nb)
	{
		flag.precis--;
		ft_putchar('0');
		(*ret)++;
	}
}
