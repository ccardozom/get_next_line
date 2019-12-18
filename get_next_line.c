/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 08:39:28 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/12 14:42:11 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	linea(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_substr(*s, 0, len);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	verifica_linea(char **s, char **line, int numbytes, int fd)
{
	if (numbytes < 0)
		return (-1);
	else if ((numbytes == 0 && s[fd] == NULL) || s[fd][0] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (linea(&s[fd], line));
}

int			get_next_line(int fd, char **line)
{
	int			numbytes;
	static char	*s[0];
	char		*buff;
	char		*tmp;

	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((numbytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[numbytes] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	free (buff);
	return (verifica_linea(s, line, numbytes, fd));
}
