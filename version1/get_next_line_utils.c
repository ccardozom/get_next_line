/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:34:40 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/03 16:32:40 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strclr(char *s)
{
	while (s != NULL && *s)
		*s++ = '\0';
}

char    *ft_strcpy(char *dest, const char *src)
{
    int         i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

size_t  ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strdup(const char *s1)
{
    char    *s;
    int     i;

    i = 0;
    while (s1[i] != '\0')
        i++;
    if (!(s = malloc((i + 1) * sizeof(char))))
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

char    *ft_strchr(const char *s, int c)
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
