/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:20 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/13 12:06:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	increment(const char *format, int *i)
{
	while (format[*i] != 'c' && format[*i] != 's' && format[*i] != 'p'
			&& format[*i] != 'd' && format[*i] != 'i' && format[*i] != 'o'
			&& format[*i] != 'u' && format[*i] != 'x' && format[*i] != 'X'
			&& format[*i] != 'f' && format[*i] != '%' && format[*i] != '\0')
		(*i) = *i + 1;
}
