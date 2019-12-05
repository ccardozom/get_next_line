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

#include "get_next_line.h"

char    *ft_strnew(size_t size)
{
    char    *str;
    size_t  i;

    i = 0;
    str = (char *)malloc(sizeof(*str) * size + 1);
    if (str == NULL)
        return (NULL);
    while (i <= size)
    {
        str[i] = '\0';
        i++;
    }
    return (str);
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

char    *ft_strdup(const char *bufer) //crea un espacio en memoria y devuelve ese espacio rellenado con los valores de bufer
{
    char    *bufer_aux;
    int     i;

    i = 0;
    while (bufer[i] != '\0')
        i++;
    if (!(bufer_aux = malloc((i + 1) * sizeof(char))))
        return (NULL);
    i = 0;
    while (bufer[i] != '\0')
    {
        bufer_aux[i] = bufer[i];
        i++;
    }
    bufer_aux[i] = '\0';
    return (bufer_aux);
}

char    *ft_strchr(const char *bufer, int c)
{
    size_t i;

    i = 0;
    while (bufer[i] != '\0')
    {
        if (c == bufer[i])
            return ((char *)bufer + i);
        i++;
    }
    if (c != '\0')
        return (NULL);
    return ((char *)bufer + i);
}
