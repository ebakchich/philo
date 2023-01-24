/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:17:43 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/24 01:24:06 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg(t_inf *ph, char *str)
{
	if (ft_strlen(str) == 4)
	{
		pthread_mutex_lock(&ph->forks[ph->nph]);
		printf("%ld %d %s\n", (ft_get_time() - ph->start), ph->index + 1, str);
	}
	else
	{
		pthread_mutex_lock(&ph->forks[ph->nph]);
		printf("%ld %d %s\n", (ft_get_time() - ph->start), ph->index + 1, str);
		pthread_mutex_unlock(&ph->forks[ph->nph]);
	}
}

void	*ft_routing(void *a)
{
	t_inf	*ph;

	ph = (t_inf *)a;
	while (1)
	{
		pthread_mutex_lock(&ph->forks[ph->index]);
		ft_print_msg(ph, "has taken left fork");
		pthread_mutex_lock(&ph->forks[(ph->index + 1) % ph->nph]);
		ft_print_msg(ph, "has taken right fork");
		ft_print_msg(ph, "is eating");
		ph->m_eat--;
		ph->l_meal = ft_get_time();
		while (ft_get_time() - ph->l_meal < ph->t_eat)
			usleep(100);
		pthread_mutex_unlock(&ph->forks[ph->index]);
		pthread_mutex_unlock(&ph->forks[(ph->index + 1) % ph->nph]);
		if (ph->ac == 6 && ph->m_eat == 0)
			break ;
		ft_print_msg(ph, "is sleeping");
		ph->s_sleep = ft_get_time();
		while (ft_get_time() - ph->s_sleep < ph->t_sleep)
			usleep(100);
		ft_print_msg(ph, "is thinking");
	}
	return (0);
}
