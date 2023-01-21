/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:28 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/21 03:10:08 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fill(t_inf *ph, char **av, int ac)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	int				index;

	i = 0;
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
		ph[i].t_eat = ft_atoi(av[3]);
		ph[i].t_sleep = ft_atoi(av[4]);
		ph[i].forks = forks;
		ph[i].index = i;
		ph[i].nph = index;
		ph[i].mutex = mutex;
		ph[i].m_eat = 0;
		ph[i].ac = ac;
		ph[i].i = 0;
		ph[i].phh = ph;
		i++;
	}
}

int	ft_creat_philo(int ac, char **av)
{
	t_inf	*ph;
	pthread_t	*pt;
	int		i;

	ph = malloc(ft_atoi(av[1]) * sizeof(t_inf));
	ft_fill(ph, av, ac);
	pt = malloc(ph[0].nph * sizeof(pthread_t));
	i = 0;
	while (i < ph[0].nph)
	{
		ph[i].start = ft_get_time();
		if (pthread_create(&pt[i], NULL, &ft_routing, &ph[i]) != 0)
			return (1);
		usleep(1);
		i++;
	}
	// i = ph[0].nph;
	// if (ph[0].nph % 2 != 0)
	// 	i = ph[0].nph - 1;
	while (1)
	{
		// if (ac == 6)
		// 	if (ph[i].m_eat == ft_atoi(av[5]))
		// 	{
		// 		usleep(100);
		// 		break ;
		// 	}
		//break ;
	}
	//printf("#####%d\n", ph[0].m_eat);
	free(pt);
	free(ph);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	if (ft_error(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	ft_creat_philo(ac, av);
	return (0);
}
