/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:45:36 by iltellat          #+#    #+#             */
/*   Updated: 2024/11/13 17:38:25 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *buffer, char *stash)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !gnl_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (stash && stash[0] == '\0')
		return (free(stash), NULL);
	return (stash);
}

char	*ft_get_remainder(char *stash)
{
	char	*remainder;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	remainder = gnl_strdup(&stash[i]);
	free(stash);
	return (remainder);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = gnl_substr(stash, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	stash = ft_readline(fd, buffer, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_get_remainder(stash);
	return (line);
}
