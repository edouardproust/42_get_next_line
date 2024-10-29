/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:00:35 by eproust           #+#    #+#             */
/*   Updated: 2024/10/29 15:17:00 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		i;

	fd = open("_test/test_lorem.txt", O_RDONLY);
	if (fd < 0)
		printf("Error opening the file.");
	if (fd < 0)
		return (1);
	i = 1;
	next_line = get_next_line(fd);
	while (next_line)
	{
		printf("%d:%s", i, next_line);
		free(next_line);
		next_line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
