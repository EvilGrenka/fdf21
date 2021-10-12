/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:43:22 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/12 14:20:43 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FT_UL_MAX	((unsigned long)(~0L))

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
void	ft_strdel(char **as);
void	ft_arrdel(char **arv);

#endif
