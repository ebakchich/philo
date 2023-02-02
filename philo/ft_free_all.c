/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:06:42 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/02 13:30:11 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_inf *ph, pthread_t *pt)
{
	int	i;

	i = 0;
	while (i <= ph[0].nph && pt != NULL)
	{
		pthread_mutex_destroy(&ph[0].forks[i]);
		pthread_detach(pt[i]);
		i++;
	}
	free(ph[0].forks);
	if (pt != NULL)
		free(pt);
	free(ph);
}
