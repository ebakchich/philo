/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:06:42 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/25 06:27:55 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_inf *ph, pthread_t *pt)
{
	int	i;

	i = 0;
	while (i <= ph[0].nph)
	{
		pthread_mutex_destroy(&ph[i].forks[i]);
		i++;
	}
	free(ph[0].forks);
	free(pt);
	free(ph);
}
