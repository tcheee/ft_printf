/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:18:20 by ayguillo          #+#    #+#             */
/*   Updated: 2018/11/23 10:58:56 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, char c)
{
	char	*dup;
	int		n;

	n = 0;
	if (!s1)
		return (NULL);
	while (s1[n] && s1[n] != c)
		n++;
	if (!(dup = (char*)malloc(sizeof(*dup) + (n + 1))))
		return (0);
	n = 0;
	while (s1[n] && s1[n] != c)
	{
		dup[n] = s1[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
