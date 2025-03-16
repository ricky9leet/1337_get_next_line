/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:46:49 by iltellat          #+#    #+#             */
/*   Updated: 2024/11/12 15:55:18 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*gnl_substr(char *s, size_t start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = gnl_strlen(s);
	if (start >= slen)
		return (gnl_strdup(""));
	if (len > slen - start)
		len = slen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	if (!stash && !buffer)
		return (NULL);
	if (!stash)
		return (gnl_strdup(buffer));
	new_stash = malloc(gnl_strlen(buffer) + gnl_strlen(stash) + 1);
	if (!new_stash)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i])
	{
		new_stash[i] = stash[i];
		i++;
	}
	while (buffer[j])
	{
		new_stash[i + j] = buffer[j];
		j++;
	}
	new_stash[i + j] = '\0';
	return (free(stash), new_stash);
}

char	*gnl_strdup(char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = gnl_strlen(s1);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
