/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:46:18 by eproust           #+#    #+#             */
/*   Updated: 2024/11/07 15:26:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * Allocates and returns s1 + s2 string (join).
 * Frees s1 at the end of the process.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free_ptrs(&s1, NULL);
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	alloc;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		substr = malloc(1);
	else
	{
		alloc = s_len - start;
		if (alloc > len)
			alloc = len;
		substr = malloc (sizeof(char) * (alloc + 1));
		if (!substr)
			return (NULL);
		while (i < alloc)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = '\0';
	return (substr);
}

void	*free_ptrs(char **p1, char **p2)
{
	if (p1 && *p1)
	{
		free(*p1);
		*p1 = NULL;
	}
	if (p2 && *p2)
	{
		free(*p2);
		*p2 = NULL;
	}
	return (NULL);
}
