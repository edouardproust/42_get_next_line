/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:45:12 by eproust           #+#    #+#             */
/*   Updated: 2024/10/29 16:49:48 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // TODO Remove this line!!
# include <fcntl.h> // TODO Remove this line!!

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
void	*free_strings(char **s1, char **s2);

#endif
