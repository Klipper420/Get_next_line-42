/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamoud <hhamoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:19:20 by hhamoud           #+#    #+#             */
/*   Updated: 2023/04/29 14:51:03 by hhamoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *join_free(char *s1, char *s2)
{
    char *new;
    
    new = ft_strjoin(s1, s2);
    free(s1);
    return (new);
}

char *read_line(char *line, int fd)
{
    char *nl;
    int size;
    char *buffer;

    nl = ft_strchr(line, '\n');
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (0);
    size = 1;
    while (!nl && size)
    {
        size = read(fd, buffer, BUFFER_SIZE);
        buffer[size] = 0;
        line = join_free(line, buffer);
        nl = ft_strchr(line, '\n');
    }
    free(buffer);
    return (line);
}


/*

line = '\0'
line = "aki is stuid\nha"
line = "hamza is sm\n"
*/

char *get_line(char *line)
{
    char *n_line;
    char *rd;
    int i;
    n_line = ft_strchr(line,'\n');
    if(!n_line)
        return(line);
   i = 0;     
    while (line[i] != '\n')
        i++;
    if(line[i] && line[i] == '\n')
        i++;
    rd = malloc(sizeof (char) * (i + 1)); // +2 for adding a newline and null terminator
    if(!rd)
        return(0);
    i = 0;
    while(line[i] && line[i] != '\n')
    {
        rd[i] = line[i];
        i++;
    }
    if (n_line)
        rd[i++] = '\n';
    rd[i] = '\0';
    return (rd);
    
}
// sddffds\nsdfd\0
char *get_next(char *line)
{
    char *n_line;
    char *rd;
    int i;
    
    i = 0;
    n_line = ft_strchr(line,'\n');
    if(!n_line)
    {
        free(line);
        return(0);
    }
   rd = malloc(sizeof (char) * (ft_strlen(n_line + 1) + 1));
    if(!rd)
    {
        free(line);
        return(0);
    }
    i = 0;
    n_line++;
    while(n_line[i])
    {
        rd[i] = n_line[i];
        i++;
    }
    rd[i] = '\0';
    free(line);
    return(rd);
}

char *get_next_line(int fd)
{
    static char *line;
    char *current;

    if (fd < 0 || fd > 256 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
    {
        return (0);
    }
    if (!line)
    {
        line = ft_strdup("");
    }
    line = read_line(line, fd);
    if (!line)
        return (0);
    current = get_line(line);
    line = get_next(line);
    return (current);
}

/*


*/

int main()
{
    int fd = open("fuk.txt", O_RDONLY);
    // get_next_line(fd);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
   printf("%s", get_next_line(fd));
   printf("%s", get_next_line(fd));
    
}
