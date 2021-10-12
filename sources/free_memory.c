/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:26:29 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/11 15:12:51 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_memory(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_axis[i]);
		i++;
	}
	free (data -> z_axis);
	free(data);
}
