# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 19:45:40 by ebakchic          #+#    #+#              #
#    Updated: 2023/01/15 20:30:35 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c ft_error.c ft_lib.c
NAME    = philo
OBJS 	= ${SRCS:.c=.o}
CC		= cc
GFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${OBJS}
	@$(CC) -o ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
