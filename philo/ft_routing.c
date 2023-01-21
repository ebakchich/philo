/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:17:43 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/21 03:17:52 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_count_eat(t_inf *ph)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < ph[0].nph)
	{
		count = count + ph[i].m_eat;
		i++;
	}
	return (count);
}

void    ft_print_msg(t_inf *ph, char *str)
{
    printf("%ld %d %s\n", (ft_get_time() - ph->start), ph->index + 1, str);
}

void	*ft_routing(void *a)
{
	t_inf	*ph;
	int		i;

	i = 0;
	ph = (t_inf *)a;
	while (1)
	{
		pthread_mutex_lock(&ph->forks[ph->index]);
		ft_print_msg(ph, "has taken left fork");
		pthread_mutex_lock(&ph->forks[(ph->index + 1) % ph->nph]);
		ft_print_msg(ph, "has taken left fork");
		ft_print_msg(ph, "is eating");
		ph->m_eat++;
		pthread_mutex_unlock(&ph->mutex);
		ph->l_meal = ft_get_time();
		while (ft_get_time() - ph->l_meal < ph->t_eat)
			usleep(10);
		if (ph->ac == 6)
			if (ph->nph * ph->ac == ft_count_eat(ph->phh))
				break ;
		pthread_mutex_unlock(&ph->forks[ph->index]);
		pthread_mutex_unlock(&ph->forks[(ph->index + 1) % ph->nph]);
		usleep(ph->t_sleep * 1000);
		ft_print_msg(ph, "is sleeping");
		//ph->s_sleep = ft_get_time();
		ft_print_msg(ph, "is thinking");
	}
	ft_print_msg(ph, "#############");
	return (0);
}
