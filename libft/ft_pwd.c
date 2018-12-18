/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:05:08 by ayguillo          #+#    #+#             */
/*   Updated: 2018/12/17 18:45:01 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_pwd(long double n, int pow)
{
	long double res;

	if (pow < 0 || n == 0)
		return (0);
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (n);
	res = 1;
	while (pow)
	{
		res = res * n;
		pow--;
	}
	return (res);
}
