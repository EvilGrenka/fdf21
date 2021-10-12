/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:53:17 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 16:53:22 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"
#include <fcntl.h>

static int	get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error_exit("Incorrect file\n", 1);
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	free(line);
	close (fd);
	return (height);
}

static int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error_exit("Incorrect file\n", 1);
	if (get_next_line(fd, &line) < 1)
		print_error_exit("Incorrect file\n", 1);
	width = get_count_words(line, ' ');
	free(line);
	close (fd);
	return (width);
}

static void	memory_z(t_fdf *data)
{
	int	i;

	i = 0;
	data -> z_axis = (int **) malloc(sizeof(int *) * (data -> height + 1));
	if (!data -> z_axis)
		print_error_exit("Memory allocate error!\n", 1);
	i = 0;
	while (i < data -> height)
	{
		data -> z_axis[i] = (int *) malloc(sizeof(int) * (data -> width + 1));
		if (!data -> z_axis[i])
			print_error_exit("Memory allocate error!\n", 1);
		i++;
	}
}

static void	fill_z(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		print_error_exit("Memory allocate error!\n", 1);
	check_map(nums);
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
}

void	read_from_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data -> height = get_height(file_name);
	data -> width = get_width(file_name);
	memory_z(data);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error_exit("Incorrect file\n", 1);
	while (get_next_line(fd, &line) > 0)
	{
		fill_z(data -> z_axis[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
