/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:51:40 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/16 18:17:19 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct t_infop
{
	int	i;
}	t_inf;

typedef struct t_info
{
	int test;
	int test2;
	int		nph;
	t_inf	*ph;
	pthread_t	*pt;
	pthread_mutex_t	mutex;
}   t_list;

int ft_error(int ac, char **av);
int	ft_atoi(const char *str);

#endif
