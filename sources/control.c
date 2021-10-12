/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:35:53 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 15:23:19 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_map(t_fdf *data, int key)
{
	if (key == ARROW_DOWN)
		data->shift_y += 15;
	if (key == ARROW_UP)
		data->shift_y -= 15;
	if (key == ARROW_LEFT)
		data->shift_x -= 15;
	if (key == ARROW_RIGHT)
		data->shift_x += 15;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	draw_our_map(data);
	print_menu(data);
}

void	zoom_map(t_fdf *data, int key)
{
	if (key == KEY_PLUS)
		data->zoom += 1;
	if (key == KEY_MINUS)
		data->zoom -= 1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	draw_our_map(data);
	print_menu(data);
}

void	set_iso_parallel(t_fdf *data, int key)
{
	if (key == ISO)
		data->is_iso = true;
	if (key == PARALLEL)
		data->is_iso = false;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	draw_our_map(data);
	print_menu(data);
}

void	rotate_map(t_fdf *data, int key)
{
	data->is_iso = true;
	if (key == ROTATE_RIGHT)
		data->alpha += 0.1;
	if (key == ROTATE_LEFT)
		data->alpha -= 0.1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	draw_our_map(data);
	print_menu(data);
}

void	zoom_z(t_fdf *data, int key)
{
	if (key == KEY_PLUS_Z)
		data -> z_zoom += 1;
	if (key == KEY_MINUS_Z)
		data -> z_zoom -= 1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	draw_our_map(data);
	print_menu(data);
}
