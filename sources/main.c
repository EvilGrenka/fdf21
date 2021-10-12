/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:58:20 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 16:58:04 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_count_words(char *line, char ch)
{
	int	count_words;

	count_words = 0;
	while (*line == ch && *line)
		++line;
	while (*line)
	{
		++count_words;
		while (*line != ch && *line)
			++line;
		while (*line == ch && *line)
			++line;
	}
	return (count_words);
}

void	print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win,
		65, 20, 0xEF8633, "How to use Map!");
	mlx_string_put(data->mlx, data->win,
		65, 60, 0xEAEAEA, "Zoom: Press +/- keys");
	mlx_string_put(data->mlx, data->win, 65,
		80, 0xEAEAEA, "Zoom Z: Press z/x keys");
	mlx_string_put(data->mlx, data->win, 65,
		100, 0xEAEAEA, "Rotate: Press '<' or '>' keys");
	mlx_string_put(data->mlx, data->win, 65,
		120, 0xEAEAEA, "Move: Arrows keys");
	mlx_string_put(data->mlx, data->win, 65,
		140, 0xEAEAEA, "By Default: R - key");
	mlx_string_put(data->mlx, data->win, 65,
		180, 0xEF8633, "Projection!");
	mlx_string_put(data->mlx, data->win, 65,
		220, 0xEAEAEA, "ISO: I - key");
	mlx_string_put(data->mlx, data->win, 65,
		240, 0xEAEAEA, "Parallel: P - key");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	init(t_fdf *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			WIDTH, HEIGHT, "FDF");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->zoom = 25;
	data->z_zoom = 1;
	data->shift_x = 550;
	data->shift_y = 200;
	data->alpha = 0.523599;
	data->is_iso = true;
	draw_our_map(data);
	print_menu(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		print_error_exit("error input! usage: ./fdf Only one argument\n", 0);
	if (!check_input_arg(argv[1]))
		print_error_exit("error input! usage: ./fdf name_map.fdf\n", 0);
	data = (t_fdf *) malloc(sizeof(t_fdf));
	if (!data)
		print_error_exit("Memory allocate error!\n", 1);
	read_from_file(argv[1], data);
	init(data);
	mlx_hook(data->win, 2, 0, pressed_key, data);
	mlx_loop(data->mlx);
	return (0);
}
