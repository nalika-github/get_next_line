/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:20:12 by ptungbun          #+#    #+#             */
/*   Updated: 2022/05/16 16:18:40 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_isend_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*room;
	size_t			i;
	unsigned char	*buf;

	room = (void *)malloc(nmemb * size);
	if (!room)
		return (0);
	i = 0;
	buf = (unsigned char *)room;
	while (i < size)
	{
		buf[i] = '\0';
		i++;
	}
	room = buf;
	return (room);
}

void	ft_trim_line(char *s1, char trim)
{
	size_t	size_s;
	size_t	i;

	i = 0;
	while (*s1 != trim)
		i++;
	size_s = 0;
	while (s1[size_s] != '\0')
		size_s++;
	while (size_s != i)
	{
		s1[size_s] = '\0';
		size_s--;
	}
}

char	*ft_strcat(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*buf;

	buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1)
		return (0);
	i = -1;
	while (s1[i++])
		buf[i] = s1[i];
	j = -1;
	while (buf[j++])
		buf[i + j] = s2[j];
	free(s1);
	return (buf);
}
