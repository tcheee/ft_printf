/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:54:53 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 15:34:49 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_precision(const char *f, int t, int *ret)
{
	int		size;

	size = flag_precision(f, t);
	if (size == 0 || size == -5)
		(*ret)--;
	return (flag_precision(f, t));
}

int		get_precision2(const char *f, int t)
{
	int		size;

	size = flag_precision(f, t);
	return (flag_precision(f, t));
}
