/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:23:13 by ptungbun          #+#    #+#             */
/*   Updated: 2022/05/11 18:14:30 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
char	*ft_strcat(char *s1, char *s2);
size_t	ft_line_len(char *stash);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmembm, size_t size);
int		ft_isn_line(char *buf);
#endif
