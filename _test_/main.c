/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:00:35 by eproust           #+#    #+#             */
/*   Updated: 2024/10/19 19:07:31 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*next_line;
	char	*filename;

	#ifdef FILENAME
		filename = FILENAME;
	#else
		filename = "test.txt"
	#endif
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		printf("Error opening the file.");
	if (fd < 0)
		return (1);
	i = 1;
	next_line = "";
	while (next_line)
	{
		next_line = get_next_line(fd);
		printf("%i: %s", i, next_line);
		free(next_line);
		i++;
	}
	close(fd);
	return (0);
}

