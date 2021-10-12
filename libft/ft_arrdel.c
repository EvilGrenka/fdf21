/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:19:57 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 16:47:22 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(char **arv)
{
	int	i;

	i = 0;
	while (arv[i])
	{
		ft_strdel(&arv[i]);
		i++;
	}
	free(arv);
	arv = NULL;
}