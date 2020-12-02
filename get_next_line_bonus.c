/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:27:41 by jlecomte          #+#    #+#             */
/*   Updated: 2020/12/02 18:04:56 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	read_n_fill(int fd, char *tmp, char **line)
{
	ssize_t rd;

	rd = read(fd, tmp, BUFFER_SIZE);
	if (rd > 0)
	{
		tmp[rd] = 0;
		if (!get_l(fd, tmp, line))
			return (-1);
		return (1);
	}
	if (rd == 0)
		return (0);
	return (-1);
}

int	get_l(int fd, char *tmp, char **line)
{
	int		nl;
	size_t	len_tmp;

	nl = index_chr(tmp, '\n');
	len_tmp = ft_strlen(tmp);
	if (nl < 0)
	{
		if (!(*line = dynq_strcat(*line, tmp, len_tmp)))
			return (0);
		read_n_fill(fd, tmp, line);
	}
	else
	{
		if (!(*line = dynq_strcat(*line, tmp, nl)))
			return (0);
		ft_memcpy(tmp, tmp + nl + 1, len_tmp - nl);
		return (1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	tmp[256][BUFFER_SIZE + 1];
	int			nl;
	size_t		len_tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(*line = (char *)malloc(1)))
		return (-1);
	len_tmp = ft_strlen(tmp[fd]);
	**line = '\0';
	if (!*tmp)
		return (read_n_fill(fd, tmp[fd], line));
	if ((nl = index_chr(tmp[fd], '\n')) != -1)
	{
		free(*line);
		if (!(*line = (char *)malloc(nl + 1)))
			return (-1);
		ft_memcpy(*line, tmp[fd], nl);
		(*line)[nl] = '\0';
		ft_memcpy(tmp[fd], (*(tmp + fd) + nl + 1), len_tmp - nl);
		tmp[fd][len_tmp - nl] = '\0';
		return (1);
	}
	if (!(*line = dynq_strcat(*line, tmp[fd], len_tmp)))
		return (-1);
	*(tmp[fd]) = '\0';
	return (read_n_fill(fd, tmp[fd], line));
}
