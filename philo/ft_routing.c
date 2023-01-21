/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:17:43 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/21 18:13:03 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg(t_inf *ph, char *str)
{
	printf("%ld %d %s\n", (ft_get_time() - ph->start), ph->index + 1, str);
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
		ft_print_msg(ph, "has taken left fork");
		ft_print_msg(ph, "is eating");
		ph->m_eat--;
		ph->l_meal = ft_get_time();
		while (ft_get_time() - ph->l_meal < ph->t_eat)
			usleep(10);
		pthread_mutex_unlock(&ph->forks[ph->index]);
		pthread_mutex_unlock(&ph->forks[(ph->index + 1) % ph->nph]);
		ft_print_msg(ph, "is sleeping");
		ph->s_sleep = ft_get_time();
		while (ft_get_time() - ph->s_sleep < ph->t_eat)
			usleep(10);
		ft_print_msg(ph, "is thinking");
		if (ph->ac == 6 && ph->m_eat == 0)
			return (0);
	}
	return (0);
}
