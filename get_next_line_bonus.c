/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:12:10 by ptungbun          #+#    #+#             */
/*   Updated: 2022/05/26 16:12:22 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		n_byte;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	n_byte = 1;
	while (n_byte && !ft_isn_line(buf) && !ft_isn_line(stash))
	{
		n_byte = read(fd, buf, BUFFER_SIZE);
		if (n_byte == -1)
		{
			free(buf);
			return (0);
		}
		buf[n_byte] = '\0';
		stash = ft_strcat(stash, buf);
	}
	free(buf);
	return (stash);
}

static char	*get_line(char *stash)
{
	size_t	line_len;
	size_t	i;
	char	*line;

	line_len = ft_line_len(stash);
	if (line_len == 0)
		return (0);
	line = ft_calloc(line_len + 1, 1);
	if (!line)
		return (0);
	i = 0;
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

static char	*update_stash(char *stash, char *line)
{
	size_t	i;
	size_t	j;
	size_t	stash_len;
	char	*new_stash;

	i = ft_strlen(line);
	stash_len = ft_strlen(stash);
	new_stash = ft_calloc(stash_len - i + 1, 1);
	j = 0;
	while (stash[i + j] != '\0')
	{
		new_stash[j] = stash[i + j];
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash[fd] = read_file(fd, stash[fd]);
	line = get_line(stash[fd]);
	if (!line)
		return (0);
	stash[fd] = update_stash(stash[fd], line);
	return (line);
}
