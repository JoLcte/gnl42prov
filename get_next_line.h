/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:25:12 by jlecomte          #+#    #+#             */
/*   Updated: 2021/04/12 23:17:14 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99
# endif

/*
** UTILS
*/

char	*ft_cpy(char *dst, char *src, int len);
char	*ft_join(char *dst, char *src, int len);
int		ft_strlen(char *s);
int		index_chr(char *s);

/*
** GET NEXT LINE
*/

int		get_l(int fd, char *buf, char **line);
int		get_next_line(int fd, char **line);
int		read_n_fill(int fd, char *buf, char **line);

#endif
