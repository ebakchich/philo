/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 05:03:07 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/26 21:21:04 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_msg(t_inf *ph, char *str)
{
	if (ft_strlen(str) == 4)
	{
		sem_wait(ph->sem->lock_print);
		printf("%ld %d %s\n", (ft_get_time() - ph->start), ph->index + 1, str);
	}
	else
	{
		sem_wait(ph->sem->lock_print);
		printf("%ld %d %s\n", (ft_get_time() - ph->start), ph->index + 1, str);
		sem_post(ph->sem->lock_print);
	}
}

void	*ft_routing(void *a)
{
	t_inf	*ph;

	ph = (t_inf *)a;
	while (1)
	{
		sem_wait(ph->sem->forks);
		ft_print_msg(ph, "has taken first fork");
		sem_wait(ph->sem->forks);
		ft_print_msg(ph, "has taken second fork");
		ft_print_msg(ph, "is eating");
		ph->m_eat--;
		ph->l_meal = ft_get_time();
		while (ft_get_time() - ph->l_meal < ph->t_eat)
			usleep(100);
		sem_post(ph->sem->forks);
		sem_post(ph->sem->forks);
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

void	ft_child(t_inf *ph)
{
	pthread_t	pth;

	pthread_create(&pth, NULL, &ft_routing, ph);
	while (1)
	{
		if (ph->ac == 6 && ph->m_eat == 0)
		{
			sem_post(ph->sem->forks);
			sem_post(ph->sem->forks);
			pthread_detach(pth);
			exit (EXIT_SUCCESS);
		}
		if (ft_get_time() - ph->l_meal >= ph->t_die)
		{
			ft_print_msg(ph, "died");
			pthread_detach(pth);
			exit (EXIT_FAILURE);
		}
	}
}
