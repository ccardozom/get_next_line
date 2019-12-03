/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@4int         get_next_line(int fd, char **line)2.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:22:59 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/03 16:32:36 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strnew(size_t size)
{
    char	*s;
    size_t	i;

    i = 0;
    s = (char*)malloc(size + 1);
    if (s == NULL)
        return (NULL);
    while (i < size)
        s[i++] = 0;
    s[size] = '\0';
    return (s);
}

char		*ft_strcat(char *dest, const char *src)
{
    int		len;
    int		i;

    i = 0;
    len = ft_strlen(dest);
    while (src[i])
    {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
    char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((joined = (char*)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2)) + 1)) == NULL)
		return (NULL);
	joined = ft_strcpy(joined, s1);
	return (ft_strcat(joined, s2));
}

char	*check_bufer(char *bufer, char **line)
{
	char *ptr_n;

	ptr_n = NULL;
	if (bufer)
	{
		if ((ptr_n = ft_strchr(bufer, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(bufer);
			ft_strcpy(bufer, ptr_n++);
		}
		else
		{
			*line = ft_strdup(bufer);
			ft_strclr(bufer);
		}
	}
	else
		*line = ft_strnew(1);
	return (ptr_n);
}
int			get_next_line(int fd, char **line)
{
	char 		buf[BUFFER_SIZE + 1];
	int			numbytes;
	char		*ptr_n;
	static char	*bufer;
	char		*tmp;

	if (!line || fd < 0)
		return (-1);
	ptr_n =	check_bufer(bufer, line); ;
	while (!ptr_n && (numbytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[numbytes] = '\0';
		if ((ptr_n = ft_strchr(buf, '\n')))
		{
			*ptr_n = '\0';
			ptr_n++;
			bufer = ft_strdup(ptr_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return ((numbytes || ft_strlen(bufer) || ft_strlen(*line)) ? 1 : 0);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("texto.txt",O_RDONLY);
	while (get_next_line(fd, &line))
	printf("%s\n", line);
}
