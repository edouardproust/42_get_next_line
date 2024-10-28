#include "get_next_line.h"

char *get_next_line(int fd) 
{
    char        *line;
    ssize_t     bytesRead;
    char        buffer[BUFFER_SIZE + 1];
    char        *line_new;
    char        *nl_ptr;
    static char *overflow = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    line = malloc(1);
    if (!line)
        return (NULL);
    line[0] = '\0';

    if (overflow)
    {
        line_new = ft_strjoin(line, overflow);
        free(overflow);
        overflow = NULL;
        free(line);
        line = line_new;
    }

    while (1)
    {
        bytesRead = read(fd, buffer, BUFFER_SIZE);
        if (bytesRead <= 0)
            break;

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
        if (nl_ptr)
        {
            *nl_ptr = '\0';
            overflow = ft_strdup(nl_ptr + 1);
            break;
        }
    }

    if (bytesRead < 0 || (bytesRead == 0 && line[0] == '\0'))
    {
        free(line);
        return (NULL);
    }

    return (line);
}

#include <fcntl.h>

int main(void)
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

