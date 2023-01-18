/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:51:40 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/18 23:37:31 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_infop
{
	int				nph;
	int				index;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
}	t_inf;

typedef struct t_info
{
	t_inf		*ph;
	pthread_t	*pt;
}	t_list;

int	ft_error(int ac, char **av);
int	ft_atoi(const char *str);

#endif
