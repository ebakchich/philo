# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 19:45:40 by ebakchic          #+#    #+#              #
#    Updated: 2023/01/20 11:23:09 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c ft_error.c ft_lib.c ft_routing.c ft_get_time.c
NAME    = philo
OBJS 	= ${SRCS:.c=.o}
CC		= cc
GFLAGS  = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): ${OBJS}
	@$(CC) -o ${NAME} ${OBJS} -pthread #-fsanitize=thread -g

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
