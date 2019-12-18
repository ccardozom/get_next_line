/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:34:40 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/05 15:12:49 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	if (!(joined = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i] = '\0';
	j = ft_strlen(joined);
	i = 0;
	while (s2[i] != '\0')
	{
		joined[i + j] = s2[i];
		i++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char		*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (void *)s;
	i = 0;
	while (*p != c)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	if (!(str = malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start] && i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}
