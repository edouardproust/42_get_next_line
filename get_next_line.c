/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:15:14 by eproust           #+#    #+#             */
/*   Updated: 2024/10/29 17:03:11 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(char *stash, int fd)
{
	char	*buffer;
	int		br;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[0] = '\0';
	br = 1;
	while (br > 0 && (!ft_strchr(buffer, '\n'))) // check stash to prevent always read
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br < 0)
			return (free_strings(&stash, &buffer));
		if (br > 0)
		{
			stash = ft_strjoin(stash, buffer);
			if (!stash)
				return (free_strings(&stash, &buffer));	
		}
	}
	free(buffer);
	return (stash);
}

char	*set_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		i--;
	line = ft_substr(stash, 0, i + 1);
	if (!line)
		return (free_strings(&stash, NULL));
	return (line);
}

char	*update_stash(int line_len, char *stash)
{
	int		len;
	char	*tmp;

	len = ft_strlen(stash);
	if (len == line_len)
	{
		free(stash);
		return (NULL);
	}
	tmp = ft_substr(stash, line_len, len);
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(stash, fd);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	if (!line)
		return (NULL);
	stash = update_stash(ft_strlen(line), stash);
	if (!stash)
		return (NULL);
	return (line);
}
