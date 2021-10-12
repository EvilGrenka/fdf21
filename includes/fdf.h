/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:57:31 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 16:27:05 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1280
# define HEIGHT 800

# include <stdbool.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "key_macos.h"

typedef struct s_b_line
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				t_b_line;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	t_data	img;
	int		width;
	int		height;
	int		**z_axis;
	int		z_zoom;
	int		z_max;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	alpha;
	bool	is_iso;

	void	*mlx;
	void	*win;
}				t_fdf;

int		get_count_words(char *line, char ch);
void	read_from_file(char *file_name, t_fdf *data);
void	isometric(float *x, float *y, int z, float alpha);
void	draw_our_map(t_fdf *data);
void	move_map(t_fdf *data, int key);
void	zoom_map(t_fdf *data, int key);
void	by_default(t_fdf *data);
void	set_iso_parallel(t_fdf *data, int key);
int		pressed_key(int key, t_fdf *data);
void	rotate_map(t_fdf *data, int key);
int		max_ab(float a, float b);
float	abs_a(float a);
void	zoom_z(t_fdf *data, int key);
void	free_memory(t_fdf *data);
bool	check_input_arg(char *arg);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_menu(t_fdf *data);
void	print_error_exit(char *msg_error, int exit_code);
void	check_map(char **nums);

#endif