/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:12:29 by asomanah          #+#    #+#             */
/*   Updated: 2024/06/12 17:02:59 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *result);
char	*ft_get_line(char *buff);
char	*ft_nextline(char *buff);
char	*ft_str_join(char *result, char *buff);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*allocate(char *buff, char *result);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
