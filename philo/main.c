/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:28 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/17 22:19:51 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routing(void *a)
{
	t_inf	*ph;
	//int	i = 0;

	ph = (t_inf *)a;
	while (1)
	{
		pthread_mutex_lock(&ph->forks[ph->index]);
		//pthread_mutex_lock(&ph->mutex);
		printf("%d is taking a left fork\n", ph->index + 1);
		//pthread_mutex_unlock(&ph->mutex);
		printf("=======> %d \n", (ph->index + 1) % ph->nph);
		pthread_mutex_lock(&ph->forks[(ph->index + 1) % ph->nph]);
		//pthread_mutex_lock(&ph->mutex);
		printf("%d is taking a right fork\n", ph->index + 1);
		//pthread_mutex_unlock(&ph->mutex);
		printf("%d is eating\n", ph->index + 1);
		//pthread_mutex_lock(&ph->mutex);
		//pthread_mutex_unlock(&ph->mutex);
		usleep(10000);
		pthread_mutex_unlock(&ph->forks[ph->index]);
		pthread_mutex_unlock(&ph->forks[(ph->index + 1) % ph->nph]);
		usleep(100);
	}
	return (0);
}

void    ft_fill(t_list *s, char **av)
{
	int	i;
	pthread_mutex_t *forks;
	pthread_mutex_t mutex;
	int		index;

	i = 0;
	s->ph = malloc(ft_atoi(av[1]) * sizeof(t_inf));
	index = ft_atoi(av[1]);
	forks = malloc(index * sizeof(pthread_mutex_t));
	pthread_mutex_init(&mutex, NULL);
	while (i < index)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	
	i = 0;
	while (i < index)
	{
		s->ph[i].forks =  forks;
		s->ph[i].index = i;
		s->ph[i].nph	= index;
		s->ph[i].mutex	= mutex;
		i++;
	}
}

int    ft_creat_philo(char **av)
{
	t_list s;
	int	i;

	s.test = 0;
	s.test2 = 0;
	ft_fill(&s, av);
	s.pt = malloc(s.ph[0].nph * sizeof(pthread_t));
	//s.ph = malloc(s.ph[0].nph * sizeof(t_inf));
	i = 0;
	printf("###### %d #######\n", s.ph[0].nph);
	while (i < s.ph[0].nph)
	{
		if (pthread_create(&s.pt[i], NULL, &ft_routing, &s.ph[i]) != 0)
			return (1);
		usleep(300);
		i++;
	}
	i = 0;
	while (i < s.ph[0].nph)
	{
		if (pthread_join(s.pt[i], NULL) != 0)
			return (1);
		i++;
	}
	//while (1);
	free(s.pt);
	free(s.ph);
	return (0);
}

int	main(int ac, char **av)
{
	int i;

	if (ft_error(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	ft_creat_philo(av);
	return (0);
}
