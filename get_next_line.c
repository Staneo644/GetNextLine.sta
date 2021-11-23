/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:10:41 by ajossera          #+#    #+#             */
/*   Updated: 2021/11/23 19:02:59 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_strnstr(char *a, char b)
{
	int	i;

	if (!a)
		return (-1);
	i = 0;
	while (a[i])
	{
		if (a[i] == b)
			return (i);
		i++;
	}
	if (b == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin(char *a, char *b)
{
	int		i;
	int		j;
	char	*rend;

	i = 0;
	j = 0;
	while (a && a[i])
		i++;
	while (b && b[j])
		j++;
	rend = malloc(sizeof(char) * (i + j + 1));
	if (!rend)
		return (NULL);
	i = -1;
	while (a && a[++i])
		rend[i] = a[i];
	j = -1;
	while (b && b[++j])
		rend[i + j] = b[j];
	rend[i + j] = '\0';
	if (a)
		free(a);
	a = NULL;
	return (rend);
}

int static	ft_get_read(int fd, char **line, char **backup)
{
	char	reading[BUFFER_SIZE + 1];
	int		o;
	int		i;

	*line = ft_strjoin(*line, *backup);
	dprintf (1, "%s", *line);
	while (ft_strnstr(*line, '\n') == -1)
	{
		o = read(fd, reading, BUFFER_SIZE);
		if (o <= 0)
		{
			if (*backup)
				free(*backup);
			*backup = NULL;
			return (1);
		}
		reading[BUFFER_SIZE] = '\0';
		*line = ft_strjoin(*line, reading);
		if (!*line)
			return (0);
	}
	i = ft_strnstr(*line, '\n');
	if (*backup)
		free(*backup);
	*backup = NULL;
	*backup = ft_strjoin(NULL, &(*line)[i - 1]);
	if (!*backup)
		return (0);
	line[0][i + 1] = '\0';
	line[0] = ft_strjoin(&line[0][0], NULL);
	dprintf (1, "A");
	if (!line[0])
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	char static	backup[OPEN_MAX] = {0};

	line = NULL;
	if (fd < 1 || fd > OPEN_MAX || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX
		|| ft_get_read(fd, &line, (char **)&(backup)) == 0)
	{
		if (line)
			free (line);
		line = NULL;
	}
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("aaa.txt", O_RDONLY);
	while (i < 10)
	{
		printf("Ce sera %s !!!\n", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
