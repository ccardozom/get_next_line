/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:32:12 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/03 16:32:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 35

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void	ft_strclr(char *s);
char    *ft_strcpy(char *dest, const char *src);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s1);
char    *ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char    *check_bufer(char *bufer, char **line);
int		get_next_line(int fd, char **line);

#endif
