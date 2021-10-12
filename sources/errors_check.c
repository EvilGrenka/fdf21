/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:48:01 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 16:58:06 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_error_exit(char *msg_error, int exit_code)
{
	ft_putstr(msg_error);
	exit(exit_code);
}

static int	count_len_massiv(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && str[1] == '0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && (str[0] == '-' || str[0] == '+'))
		return (0);
	return (1);
}

void	check_map(char **nums)
{
	char	**tmp;
	int		map_len;
	int		i;

	i = 0;
	map_len = count_len_massiv(nums);
	while (i < map_len)
	{
		tmp = ft_split(nums[i], ',');
		if (!ft_is_number(tmp[0]))
		{
			i = 0;
			while (nums[i])
			{
				free(nums[i]);
				i++;
			}
			free(nums);
			ft_arrdel(tmp);
			print_error_exit("Incorrect map\n", 1);
		}
		i++;
		ft_arrdel(tmp);
	}
}
