/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:47:15 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/08 17:37:11 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int	readed;
	int	i;

	i = 0;
	*line = malloc(4 * 1024 * 1024);
	if (!line)
		return (-1);
	readed = read(fd, *line + i, 1);
	while (readed > 0)
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
		readed = read(fd, *line + i, 1);
	}
	(*line)[i] = '\0';
	return (readed);
}
