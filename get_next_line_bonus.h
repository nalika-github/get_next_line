/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:15:46 by ptungbun          #+#    #+#             */
/*   Updated: 2022/05/26 16:15:51 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strcat(char *s1, char *s2);
size_t	ft_line_len(char *stash);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmembm, size_t size);
int		ft_isn_line(char *buf);
#endif
