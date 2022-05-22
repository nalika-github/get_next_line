/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:19:41 by ptungbun          #+#    #+#             */
/*   Updated: 2022/05/16 17:43:55 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	scan_st(char *buf, size_t lo, char *st)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (ft_strlen(st) >= lo)
		return (0);
	if (ft_strlen(st) < lo && (lo - ft_strlen(buf)) < ft_strlen(st))
	{
		temp = ft_calloc((lo - ft_strlen(buf)), 1);
		i = (2 * (int)ft_strlen(buf) - lo) + 1;
		j = 0;
		while (i-- != 0)
			j++;
		while (i <= ft_strlen(buf))
		{
			temp[i] = buf[j];
			i++;
			j++;
		}
		temp[ft_strlen(temp)] = '\0';
		buf = temp;
		free(temp);
		return (1);
	}
	return (1);
}

char	*update_line(char *line, char *buf, size_t lo, char *st)
{
	if (!line)
		line = ft_calloc(1, 1);
	if (!line || !buf)
		return (0);
	if (scan_st(buf, lo, st))
		line = ft_strcat(line, buf);
	ft_trim_line(new_line, '\n');
	free (line);
	return (new_line);
}

char	*update_st(char *line, char *st)
{
	char	*new_st;

	if (!line)
		return (0);
	new_st = malloc(sizeof(char) * (ft_strlen(st) + ft_strlen(line) + 1));
	if (!new_st)
		return (0);
	new_st = ft_strcat(st, line);
	ft_trim_line(new_st, '\n');
	free (line);
	return (new_st);
}

char	*read_file(int fd, char *st)
{
	char	*buf;
	char	*line;
	int		n_byte;
	size_t	lo;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	n_byte = 1;
	lo = -1;
	while (n_byte)
	{
		n_byte = read(fd, buf, BUFFER_SIZE);
		lo = lo + n_byte;
		if (n_byte == -1)
		{
			free(buf);
			return (0);
		}
		buf[n_byte] = '\0';
		line = update_line(line, buf, lo, st);
		n_byte = ft_isend_line(line);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*st;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!st)
		st = ft_calloc(1, 1);
	line = read_file(fd, st);
	st = update_st(st, line);
	return (line);
}
