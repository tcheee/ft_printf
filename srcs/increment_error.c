/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:18:32 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/18 13:50:16 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	increment_error(const char *f, int *i, int *sum, int *b)
{
	int	t;
	int	j;

	j = *i;
	t = *i;
	while (f[j] != '\0' && (f[j] < 58 ||  f[j] > 126))
	{
		if (f[j] >= '0' && f[j] <= '9')
			(*i)++;
		else if (f[j] == '.' || f[j] == '+' || f[j] == '#')
			(*i)++;
		else if (f[j] == '-')
		{
			if (*b == -5)
				if (flag_space_neg_nb_error(f, t) != 0)
					*b = -flag_space_neg_nb_error(f, t);
			(*i)++;
		}
		else if (f[j] == ' ')
			(*i)++;
		j++;
	}
	if (ft_atoi(&f[t]) > 0)
		flag_space(f, 0, t, sum);
}
