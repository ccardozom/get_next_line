/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 08:39:28 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/05 15:12:40 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char    *subs;
    size_t  i;

    if (s == NULL)
        return (NULL);
    subs = ft_strnew(len);
    if (subs == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        subs[i] = s[start + i];
        i++;
    }
    return (subs);
}

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		strlen;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(strlen);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[1024];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
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
	return ((ret == 0 && s[fd] == NULL) ? 0 : (appendline(&s[fd], line)));
}

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;

	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/empty_lines", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 9)
		printf("\nRight number of lines\n");
	else if (j != 9)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("======== TEST 3 : The Empty File =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/empty_file", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 4 : One New Line ==========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/1_newline", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 2)
		printf("\nRight number of lines\n");
	else if (j != 2)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 5 : Four New Lines ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/4_newlines", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 5)
		printf("\nRight number of lines\n");
	else if (j != 5)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("============== TEST 6 : 42 ===============\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/41_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/42_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{

		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/43_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("============= TEST 7 : Marge =============\n");
	printf("==========================================\n\n");

	int fd2;

	if (!(fd = open("files/half_marge_top", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	if (!(fd2 = open("files/half_marge_bottom", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	while ((i = get_next_line(fd2, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	printf("%s\n", line);
	close(fd);
	close(fd2);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 25)
		printf("\nRight number of lines\n");
	else if (j != 25)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 8 : Wrong Input ===========\n");
	printf("==========================================\n\n");

	if (get_next_line(180, &line) == -1)
		printf("Well Done, you return -1 if no FD\n\n");
	else
		printf("Not Good, you don't return -1 if no FD\n\n");
	return (0);
}
