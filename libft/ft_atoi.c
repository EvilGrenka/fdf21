/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:15:57 by rnoriko           #+#    #+#             */
/*   Updated: 2021/04/30 16:01:04 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char			*tmp;
	int				sign;
	unsigned long	res;
	unsigned long	lim;

	lim = (unsigned long)((FT_UL_MAX >> 1) / 10);
	sign = 1;
	res = 0;
	tmp = (char *)str;
	while (*tmp == '\f' || *tmp == '\r' || *tmp == ' '
		|| *tmp == '\t' || *tmp == '\n' || *tmp == '\v')
		tmp++;
	if (*tmp == '-')
		sign = -1;
	if (*tmp == '+' || sign == -1)
		tmp++;
	while (ft_isdigit(*tmp))
	{
		if ((res > lim || (res == lim && (*tmp - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > lim || (res == lim && (*tmp - '0') > 8)) && sign == -1)
			return (0);
		res = (res * 10) + (*tmp++ - '0');
	}
	return ((int)(res * sign));
}
