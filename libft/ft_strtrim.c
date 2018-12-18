/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:14:00 by ayguillo          #+#    #+#             */
/*   Updated: 2018/11/23 11:06:26 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		pre;
	int		len;
	int		i;
	int		size;

	pre = -1;
	size = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	while (s[++pre] == ' ' || s[pre] == '\t' || s[pre] == '\n')
		len--;
	if (len <= 0)
		len = 0;
	if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	i = 0;
	while (len-- >= 0)
		str[i++] = s[pre++];
	str[i] = '\0';
	return (str);
}
