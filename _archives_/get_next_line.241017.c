/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:46:09 by eproust           #+#    #+#             */
/*   Updated: 2024/10/17 19:14:17 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Return line + '\n' if not the last line. Return just line if is the last line.
 */
char *get_next_line(int fd)
{
	char		*line;
	ssize_t		bytesRead;
	char		buffer[BUFFER_SIZE + 1];
	char		*line_new;
	char		*nl_ptr;
	static char	*overflow;

	bytesRead = read(fd, buffer, BUFFER_SIZE);
	if (bytesRead <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (overflow)
	{
		line_new = ft_strjoin(line, overflow);
		free(overflow);
		free(line);
		line = line_new;
	}
	while (bytesRead > 0)
	{
		buffer[bytesRead] = '\0';
		line_new = ft_strjoin(line, buffer);
		if (!line_new)
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = line_new;
	
		nl_ptr = ft_strchr(line, '\n');
		if (!nl_ptr)	
			bytesRead = read(fd, buffer, BUFFER_SIZE);
		else
		{
			overflow = ft_strdup(nl_ptr);
		//	overflow = ft_substr(line, nl_ptr - line + 1, nl_ptr - line);
		//	nl_ptr[1] = '\0';
			break;
		}
	}
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);

	// TODO Asegúrate de que tu función se comporta adecuadamente cuando lea de stdin
	// TODO Test with BUFFER_SIZE 9999, 1 or 10000000: cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c

	return (0);
}
