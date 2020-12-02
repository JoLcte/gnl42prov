/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:21:09 by jlecomte          #+#    #+#             */
/*   Updated: 2020/12/02 18:30:40 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int		index_chr(char *s, char c)
{
	char *const save = s;

	while (*s)
		if (*s++ == c)
			return (s - 1 - save);
	return (-1);
}

char	*ft_memcpy(char *dst, char *src, size_t n)
{
	char	*p_dst;
	char	*p_src;

	p_dst = dst;
	p_src = src;
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}

size_t	ft_strlen(char *s)
{
	char *const save = s;

	if (!s)
		return (0);
	while (*s)
		s++;
	return (s - save);
}

char	*dynq_strcat(char *dst, char *src, int len)
{
	char			*swp;
	const size_t	len_dst = ft_strlen(dst);

	if (!src)
		return (NULL);
	if (!(swp = (char *)malloc(len_dst + 1)))
		return (NULL);
	ft_memcpy(swp, dst, len_dst);
	swp[len_dst] = '\0';
	free(dst);
	if (!(dst = (char *)malloc(len_dst + len + 1)))
		return (NULL);
	ft_memcpy(dst, swp, len_dst);
	free(swp);
	ft_memcpy(dst + len_dst, src, len);
	dst[len_dst + len] = '\0';
	return (dst);
}