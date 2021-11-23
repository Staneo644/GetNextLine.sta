/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:47:27 by ajossera          #+#    #+#             */
/*   Updated: 2021/11/19 13:48:49 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_strjoin(char *a, char *b);
int static	ft_get_read(int fd, char **line, char **backup);
char		*get_next_line(int fd);

#endif