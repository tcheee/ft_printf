/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:22:02 by ayguillo          #+#    #+#             */
/*   Updated: 2018/11/22 14:55:15 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_new_join(char **line, char *buff)
{
	char	*tmp;
	char	*dup;

	tmp = *line;
	if (!(dup = ft_strcdup(buff, '\n')))
		return (-1);
	*line = ft_strjoin(tmp, dup);
	ft_strdel(&tmp);
	ft_strdel(&dup);
	return (1);
}

static int	ft_end(char *buff, int ret, char **line)
{
	if (ft_strchr(buff, '\n') != NULL && buff)
		ft_memmove(buff, ft_strchr(buff, '\n') + 1,
				ft_strlen(ft_strchr(buff, '\n')));
	else
		buff[0] = '\0';
	if (ret == 0 && ft_strcmp(*line, "") == 0 && buff[0] == '\0')
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				ret;
	int				end;

	ret = BUFF_SIZE;
	if (!line || fd == -1 || !(*line = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = '\0';
	while (ft_strchr(buff, '\n') == NULL && ret == BUFF_SIZE)
	{
		ft_new_join(line, buff);
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		{
			ft_strdel(line);
			return (-1);
		}
		buff[ret] = '\0';
	}
	ft_new_join(line, buff);
	end = ft_end(buff, ret, line);
	return (end);
}
