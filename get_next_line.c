/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:19:41 by ptungbun          #+#    #+#             */
/*   Updated: 2022/05/22 11:09:04 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		n_byte;

	if (!stash)
		stash = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	n_byte = 1;
	while (n_byte && !ft_isn_line(stash))
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

static char	*get_line(char *stash, size_t line_len)
{
	size_t	i;
	char	*line;

	if (!stash)
		return (0);
	if (line_len == 0)
		return (0);
	line = ft_calloc(line_len + 1, 1);
	if (!line)
	{
		free (line);
		return (0);
	}
	i = 0;
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

static char	*update_stash(char *stash, size_t line_len)
{
	size_t	i;
	size_t	j;
	size_t	stash_len;
	char	*new_stash;

	stash_len = ft_strlen(stash);
	i = line_len;
	new_stash = ft_calloc(stash_len - i + 1, 1);
	j = 0;
	while (stash[i + j] != '\0')
	{
		new_stash[j] = stash[i + j];
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	if (line_len == stash_len)
	{
		free (new_stash);
		return (NULL);
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	size_t		line_len;
	int			n_byte;

	n_byte = read(fd, NULL, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || n_byte < 0)
		return (0);
	stash = read_file(fd, stash);
	if (!stash)
		return (0);
	line_len = ft_line_len(stash);
	line = get_line(stash, line_len);
	stash = update_stash(stash, line_len);
	if (!stash)
	{
		free (stash);
		return (line);
	}
	return (line);
}
