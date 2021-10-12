# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 13:35:32 by rnoriko           #+#    #+#              #
#    Updated: 2021/10/12 14:29:57 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC				=	libft.h

SRCS			=	ft_atoi.c ft_isdigit.c ft_split.c ft_putstr.c ft_strdel.c ft_arrdel.c

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(INC)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
