/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:28 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/16 14:12:29 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_fill(t_list *s, char **av)
{
	s->nph = ft_atoi(av[1]);
}

void    ft_creat_philo(char **av)
{
	t_list *s;

	ft_fill(s, av);
	s->ph = malloc(s->nph * sizeof(t_inf));
	free(s->ph);
}

int	main(int ac, char **av)
{
	if (ft_error(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	ft_creat_philo(av);
	return (0);
}
