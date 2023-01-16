/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:28 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/16 18:19:06 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routing(void *a)
{
	t_list	*s;

	s = (t_list *)a;
	pthread_mutex_lock(&s->mutex);
	for (int i = 0; i < 100000; i++) {
		s->test++;
	}
	pthread_mutex_unlock(&s->mutex);
	for (int k = 0; k < 100000; k++) {
		s->test2++;
	}
	return (0);
}

void    ft_fill(t_list *s, char **av)
{
	s->nph = ft_atoi(av[1]);
}

int    ft_creat_philo(char **av)
{
	t_list s;
	int	i;

	s.test = 0;
	s.test2 = 0;
	ft_fill(&s, av);
	s.pt = malloc(s.nph * sizeof(pthread_t));
	s.ph = malloc(s.nph * sizeof(t_inf));
	pthread_mutex_init(&s.mutex, NULL);
	i = 0;
	while (i < s.nph)
	{
		if (pthread_create(&s.pt[i], NULL, &ft_routing, &s) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < s.nph)
	{
		if (pthread_join(s.pt[i], NULL) != 0)
			return (1);
		i++;
	}
	printf("%d\n", s.test);
	printf("%d\n", s.test2);
	pthread_mutex_destroy(&s.mutex);
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
