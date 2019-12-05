/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:32:12 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/05 15:12:44 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char    *ft_strnew(size_t size);
void    ft_strdel(char **as);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strcpy(char *dest, const char *src);
size_t  ft_strlen(const char *str);
char	*ft_strdup(const char *bufer);
char	*ft_strchr(const char *bufer, int c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

#endif
