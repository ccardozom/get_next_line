/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:32:12 by ccardozo          #+#    #+#             */
/*   Updated: 2019/11/29 13:10:41 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE

# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>

char				*ft_strcat(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strchr(const char *s, int c);
int					ft_new_line(char **s, char **line, int fd, int ret);
int					get_next_line(int fd, char **line);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
void				*ft_memmove(void *dst, void *src, size_t len);
char				*ft_strdup(const char *s1);
#endif
