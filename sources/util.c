/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:22:25 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 15:16:39 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	max_ab(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	abs_a(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	by_default(t_fdf *data)
{
	data->zoom = 25;
	data->z_zoom = 1;
	data->shift_x = 550;
	data->shift_y = 200;
	data->alpha = 0.523599;
	data->is_iso = true;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	draw_our_map(data);
	print_menu(data);
}

int	pressed_key(int key, t_fdf *data)
{
	if (key == ARROW_UP || key == ARROW_DOWN
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
		move_map(data, key);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		zoom_map(data, key);
	else if (key == ISO || key == PARALLEL)
		set_iso_parallel(data, key);
	else if (key == ROTATE_LEFT || key == ROTATE_RIGHT)
		rotate_map(data, key);
	else if (key == KEY_RESET)
		by_default(data);
	else if (key == KEY_PLUS_Z || key == KEY_MINUS_Z)
		zoom_z(data, key);
	else if (key == ESC)
	{
		free_memory(data);
		exit(0);
	}
	return (0);
}

bool	check_input_arg(char *arg)
{
	while (*arg)
	{
		if (*arg == '.')
			return (true);
		arg++;
	}
	return (false);
}
