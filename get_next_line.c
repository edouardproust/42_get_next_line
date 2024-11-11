/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:15:14 by eproust           #+#    #+#             */
/*   Updated: 2024/11/11 17:23:41 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_stash(char **stash, int fd);
static char	*set_line(char **stash);
static char	*update_stash(int line_len, char **stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(&stash, fd);
	if (!stash)
		return (NULL);
	line = set_line(&stash);
	if (!line)
		return (NULL);
	stash = update_stash(ft_strlen(line), &stash);
	return (line);
}

static char	*fill_stash(char **stash, int fd)
{
	char	*buffer;
	int		br;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_ptrs(stash, NULL));
	buffer[0] = '\0';
	br = 1;
	while (!ft_strchr(buffer, '\n') && br != 0)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br < 0)
			return (free_ptrs(&buffer, stash));
		if (br > 0)
		{
			buffer[br] = '\0';
			*stash = ft_strjoin(*stash, buffer);
			if (!*stash)
				return (free_ptrs(&buffer, NULL));
		}
	}
	free_ptrs(&buffer, NULL);
	return (*stash);
}

static char	*set_line(char **stash)
{
	char	*line;
	int		i;

	i = 0;
	while ((*stash)[i] != '\n' && (*stash)[i] != '\0')
		i++;
	if ((*stash)[i] == '\0' && i > 0)
		i--;
	line = ft_substr(*stash, 0, i + 1);
	if (!line)
		return (free_ptrs(stash, NULL));
	if (ft_strlen(line) == 0)
		return (free_ptrs(&line, stash));
	return (line);
}

static char	*update_stash(int line_len, char **stash)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*stash);
	if (len == line_len)
		return (free_ptrs(stash, NULL));
	tmp = ft_substr(*stash, line_len, len);
	free_ptrs(stash, NULL);
	return (tmp);
}
