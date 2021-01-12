/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:21:46 by jlecomte          #+#    #+#             */
/*   Updated: 2021/01/12 17:52:59 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99
# endif

int		get_next_line(int fd, char **line);
int		read_n_fill(int fd, char *tmp, char **line);
int		get_l(int fd, char *tmp, char **line);
int		index_chr(char *s, char c);
char	*ft_memcpy(char *dst, char *src, size_t n);
size_t	ft_strlen(char *s);
char	*dynq_strcat(char *dst, char *src, int len);
char	*len_strdup(char *dst, char *src, int len);

#endif
