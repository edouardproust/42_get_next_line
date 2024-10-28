/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:15:14 by eproust           #+#    #+#             */
/*   Updated: 2024/10/27 19:22:15 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **stash);
static int	alloc_strings(char **stash, char **buffer);
static void	*free_strings(char **stash, char **buffer);

char	*get_next_line(int fd)
{
	static char	*stash;
	int			bytes_read;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || !alloc_strings(&stash, &buffer))
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_strings(&stash, &buffer));
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free_strings(&stash, &buffer));	
	}
	free(buffer); 
	return (get_line(&stash));
}

static char *get_line(char **stash)
{
    char    *line;
    int     i;
    char    *tmp;

    i = 0;
    while ((*stash)[i] != '\n' && (*stash)[i] != '\0')
        i++;

    if ((*stash)[i] == '\0')
        return (NULL);

    line = ft_substr(*stash, 0, i + 1);
    if (!line)
		return (free_strings(stash, NULL));
    tmp = ft_substr(*stash, i + 1, ft_strlen(*stash) - i - 1);
    //free_strings(stash, NULL);
    *stash = tmp;
    if (!(*stash))
        free_strings(stash, &line);
    return (line);
}

/*
static char	*get_line(char **stash, char **buffer)
{
	char	*line;
	char	*nl_ptr;

	line = NULL;
	nl_ptr = ft_strchr(*stash, '\n');
	if (nl_ptr)
	{
		line = ft_substr(*stash, 0, nl_ptr - *stash + 1);
		if (!line)	
			return (free_strings(stash, buffer));	
		char *tmp = ft_substr(nl_ptr + 1, 0, ft_strlen(nl_ptr + 1));
		free(*stash);
		*stash = tmp;
		if (!*stash)	
			return (free_strings(stash, buffer));	
	}
	else if(*stash)
		free(*stash);
	return (line);
}
*/

static int	alloc_strings(char **stash, char **buffer)
{
	int	i;

	if (!*stash)
	{
		*stash = malloc(sizeof(char));
		if (!*stash)
			return (0);
		(*stash)[0] = '\0';
	}
	*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
	{
		free(*stash);
		*stash = NULL;
		return (0);
	}
	i = 0;
	while (i <= BUFFER_SIZE)
		(*buffer)[i++] = '\0';
	return (1);
}

static void	*free_strings(char **stash, char **buffer)
{
	if (**stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	if (**buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}
