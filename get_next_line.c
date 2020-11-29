/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:09:45 by jlecomte          #+#    #+#             */
/*   Updated: 2020/11/29 22:28:52 by jlecomte         ###   ########.fr       */
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
	static char	tmp[BUFFER_SIZE + 1];
	int			nl;
	size_t		len_tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(*line = (char *)malloc(1)))
		return (-1);
	len_tmp = ft_strlen(tmp);
	**line = '\0';
	if (!*tmp)
		return (read_n_fill(fd, tmp, line));
	if ((nl = index_chr(tmp, '\n')) != -1)
	{
		free(*line);
		if (!(*line = (char *)malloc(nl + 1)))
			return (-1);
		ft_memcpy(*line, tmp, nl);
		(*line)[nl] = '\0';
		ft_memcpy(tmp, (tmp + nl + 1), len_tmp - nl);
		tmp[len_tmp - nl] = '\0';
		return (1);
	}
	if (!(*line = dynq_strcat(*line, tmp, len_tmp)))
		return (-1);
	*tmp = '\0';
	return (read_n_fill(fd, tmp, line));
}
