/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.241019.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:15:14 by eproust           #+#    #+#             */
/*   Updated: 2024/10/19 14:59:42 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line = NULL;
	static char	*overflow = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*nl_index = NULL;
	int			bytesRead;

	line = malloc(1);
	line[0] = '\0';
	if (overflow) {
		line = ft_strjoin(line, overflow);
		//free(overflow);
		//overflow = NULL;
	}
	nl_index = ft_strchr(line, '\n');
	if (nl_index) {
		overflow = ft_strdup(nl_index + 1);
		nl_index[1] = '\0';
		return (line);
	}
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	if (bytesRead == 0)
		overflow = NULL;
	while (bytesRead > 0)
	{
		buffer[bytesRead] = '\0';
		line = ft_strjoin(line, buffer);
		nl_index = ft_strchr(line, '\n');
		if (nl_index) {
			overflow = ft_strdup(nl_index + 1);
			nl_index[1] = '\0';
			return (line);
		}
		bytesRead = read(fd, buffer, BUFFER_SIZE);
	}
	if (!ft_strlen(line))
		return (NULL);
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("1: %s", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
	printf("3: %s", get_next_line(fd));
	printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd));
	printf("7: %s", get_next_line(fd));
	printf("8: %s", get_next_line(fd));
	printf("9: %s", get_next_line(fd));
	close(fd);

	return (0);
}
