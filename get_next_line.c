/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:25:58 by ccardozo          #+#    #+#             */
/*   Updated: 2019/11/29 13:01:55 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strcat(char *dest, const char *src)
{
	int len;
	int i;

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

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return ((char *)s + i);
		i++;
	}
	if (c != '\0')
		return (NULL);
	return ((char *)s + i);
}

static char	*biggerbuf(int const fd, char *buf, int *ret)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFFER_SIZE);
//	printf("\n%d\n",*ret);
	if (*ret < BUFFER_SIZE && tmp[*ret] != '\n')
	{
		tmp[*ret] = '\0';
		tmp[*ret + 1] = '\n';
	}
	else
		tmp[*ret + 1] = '\0';
	tmp2 = buf;
	buf = ft_strjoin(buf, tmp);
	ft_strdel(&tmp2);
	return (buf);
}

int			get_next_line(int fd, char **line)
{
	static char		*buf;
	int				numbytes;
	char			*str;

	if (!line || fd < 0)
		return (-1);
	numbytes = 1;
	if (!buf)
		buf = ft_strnew(0);
	while (numbytes > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != NULL)
		{
			*str = 0;
			*line = ft_strdup(buf);
			ft_memmove(buf, str, ft_strlen(str + 1));
			return (1);
		}
uf = biggerbuf(fd, buf, &numbytes);
	}
	if (numbytes == 0)
		*line = ft_strnew(0);
	return (numbytes);
}
