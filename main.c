/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:00:35 by eproust           #+#    #+#             */
/*   Updated: 2024/10/31 16:46:54 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("gnlTester/files/nl", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening the file.");
		return (1);
	}
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%d:%s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
