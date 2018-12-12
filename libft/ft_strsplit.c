/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:13:27 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/16 14:18:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		if (!(str[i] == c) && str[i] != '\0')
		{
			while (str[i] != '\0' && (!(str[i] == c)))
				i++;
			word++;
		}
	}
	return (word);
}

static int		count_letters(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char		**fill_tab(char **tab, char const *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j < count_words(str, c))
	{
		k = 0;
		while (str[i] == c)
			i++;
		if (!(tab[j] = malloc(sizeof(char) * (count_letters(&str[i], c) + 1))))
			return (NULL);
		while (str[i] != '\0' && str[i] != c)
			tab[j][k++] = str[i++];
		tab[j][k] = '\0';
		j++;
		while (str[i] == c)
			i++;
	}
	tab[count_words(str, c)] = 0;
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;

	if (str == NULL)
		return (NULL);
	if (!(tab = malloc(sizeof(char*) * (count_words(str, c) + 1))))
		return (NULL);
	fill_tab(tab, str, c);
	return (tab);
}
