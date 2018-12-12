/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:56:19 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/13 11:39:12 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		new_len(char const *s)
{
	int i;
	int len;
	int new_len;

	i = 0;
	len = ft_strlen(s);
	while (s[i] != '\0' && (s[i] == ' ' ||
				s[i] == ',' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[len - 1] == ' ' || s[len - 1] == ',' || s[len - 1] == '\n'
			|| s[len - 1] == '\t')
		len--;
	new_len = len - i;
	if (new_len < 0)
		new_len = 0;
	return (new_len);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(*new) * (new_len(s) + 1))))
		return (NULL);
	while (s[i] != '\0' && (s[i] == ' ' ||
				s[i] == ',' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j < new_len(s))
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
