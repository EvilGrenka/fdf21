/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:58:02 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 15:15:08 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_parametrs(t_b_line *bline, t_fdf *data)
{
	int	z;
	int	z1;

	z = data->z_axis[(int)bline->y][(int)bline->x] * data->z_zoom;
	z1 = data->z_axis[(int)bline->y1][(int)bline->x1] * data->z_zoom;
	if (z > 0 || z1 > 0)
		data->color = 0xa1251b;
	else if (z < 0 || z1 < 0)
		data->color = 0xe2e83c;
	else
		data->color = 0xffffff;
	bline->x *= data->zoom;
	bline->y *= data->zoom;
	bline->x1 *= data->zoom;
	bline->y1 *= data->zoom;
	if (data->is_iso)
	{
		isometric (&bline->x, &bline->y, z, data->alpha);
		isometric (&bline->x1, &bline->y1, z1, data->alpha);
	}
	bline->x += data->shift_x;
	bline->y += data->shift_y;
	bline->x1 += data->shift_x;
	bline->y1 += data->shift_y;
}

static void	bresenham(t_b_line bline, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max_step;

	set_parametrs(&bline, data);
	x_step = bline.x1 - bline.x;
	y_step = bline.y1 - bline.y;
	max_step = max_ab(abs_a(x_step), abs_a(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while ((int)(bline.x - bline.x1) || (int)(bline.y - bline.y1))
	{
		my_mlx_pixel_put(&data->img, bline.x, bline.y, data->color);
		bline.x += x_step;
		bline.y += y_step;
	}
}

static t_b_line	get_blinex(t_b_line bline, int x, int y)
{
	bline.x = x;
	bline.y = y;
	bline.x1 = x + 1;
	bline.y1 = y;
	return (bline);
}

static t_b_line	get_bliney(t_b_line bline, int x, int y)
{
	bline.x = x;
	bline.y = y;
	bline.x1 = x;
	bline.y1 = y + 1;
	return (bline);
}

void	draw_our_map(t_fdf *data)
{
	int			x;
	int			y;
	t_b_line	bline;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < (data->width) - 1)
			{
				bline = get_blinex(bline, x, y);
				bresenham(bline, data);
			}
			if (y < (data -> height) - 1)
			{
				bline = get_bliney(bline, x, y);
				bresenham(bline, data);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
