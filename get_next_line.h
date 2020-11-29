/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:25:12 by jlecomte          #+#    #+#             */
/*   Updated: 2020/11/29 20:42:53 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99
# endif

int		get_next_line(int fd, char **line);
int		read_n_fill(int fd, char *tmp, char **line);
int		index_chr(char *s, char c);
int		get_l(int fd, char *tmp, char **line);
char	*ft_memcpy(char *dst, char *src, size_t n);
size_t	ft_strlen(char *s);
char	*dynq_strcat(char *dst, char *src, int len);

#endif
