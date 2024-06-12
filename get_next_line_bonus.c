/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:11:51 by asomanah          #+#    #+#             */
/*   Updated: 2024/06/12 17:52:07 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* We can achieve this by using an array of 
static pointers indexed by the file descriptor */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_calloc(1, 1);
	if (!buff[fd])
	{
		free(buff[fd]);
		return (NULL);
	}
	buff[fd] = ft_read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_get_line(buff[fd]);
	buff[fd] = ft_nextline(buff[fd]);
	return (line);
}

char	*ft_read_file(int fd, char *result)
{
	int		bytes_read;
	char	*buff;

	bytes_read = 1;
	buff = NULL;
	buff = allocate(buff, result);
	if (!buff)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buff);
			free (result);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		result = ft_str_join(result, buff);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free (buff);
	return (result);
}

char	*ft_get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_nextline(char *buff)
{
	char	*next;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	next = ft_calloc(((ft_strlen(buff)) - i + 1), sizeof(char));
	if (!next)
	{
		free (next);
		return (NULL);
	}
	i++;
	while (buff[i])
		next[a++] = buff[i++];
	free (buff);
	return (next);
}

char	*allocate(char *buff, char *result)
{
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(buff);
		free(result);
		return (NULL);
	}
	return (buff);
}
