# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 21:21:14 by ebakchic          #+#    #+#              #
#    Updated: 2023/02/01 15:37:39 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main_bonus.c ft_error_bonus.c ft_lib_bonus.c ft_child_bonus.c ft_get_time_bonus.c ft_free_all_bonus.c
NAME    = philo_bonus
OBJS 	= ${SRCS:.c=.o}
CC		= cc
GFLAGS  = -Wall -Wextra -Werror #-fsanitize=thread -g

all: $(NAME)

$(NAME): ${OBJS}
	@$(CC) $(GFLAGS) -o ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
