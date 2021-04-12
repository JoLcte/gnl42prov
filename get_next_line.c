/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:09:45 by jlecomte          #+#    #+#             */
/*   Updated: 2021/04/13 00:56:06 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	**init_line(char **line)
{
	*line = (char *)malloc(1);
	if (!*line)
		return (NULL);
	**line = 0;
	return (line);
}

int	read_n_fill(int fd, char *buf, char **line)
{
	ssize_t	rd;

	rd = read(fd, buf, BUFFER_SIZE);
	if (rd > 0)
	{
		buf[rd] = 0;
		return (get_l(fd, buf, line));
	}
	if (rd == 0)
	{
		*buf = 0;
		return (0);
	}
	free(*line);
	*line = 0;
	return (-1);
}

int	get_l(int fd, char *buf, char **line)
{
	const int	nl = index_chr(buf);
	const int	l_buf = ft_strlen(buf);

	if (nl == -1)
	{
		*line = ft_join(*line, buf, l_buf);
		if (!*line)
			return (-1);
		return (read_n_fill(fd, buf, line));
	}
	else
	{
		*line = ft_join(*line, buf, nl);
		if (!*line)
			return (-1);
		ft_cpy(buf, buf + nl + 1, l_buf - nl);
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			nl;
	const int	l_buf = ft_strlen(buf);

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1 || !line)
		return (-1);
	line = init_line(line);
	if (!line)
		return (-1);
	if (!*buf)
		return (read_n_fill(fd, buf, line));
	nl = index_chr(buf);
	if (nl > -1)
	{
		*line = ft_join(*line, buf, nl);
		if (!*line)
			return (-1);
		ft_cpy(buf, (buf + nl + 1), l_buf - nl);
		buf[l_buf - nl] = 0;
		return (1);
	}
	*line = ft_join(*line, buf, l_buf);
	if (!*line)
		return (-1);
	return (read_n_fill(fd, buf, line));
}
