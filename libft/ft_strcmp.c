/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:08:36 by ayguillo          #+#    #+#             */
/*   Updated: 2018/11/13 16:04:27 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int					n;
	unsigned const char *us1;
	unsigned const char *us2;

	us1 = (unsigned const char*)s1;
	us2 = (unsigned const char*)s2;
	n = 0;
	while ((us1[n] || us2[n]) && (us1[n] == us2[n]))
		n++;
	if (us1[n] == '\0' || us2[n] == '\0' || us1[n] != us2[n])
		return (us1[n] - us2[n]);
	return (0);
}
