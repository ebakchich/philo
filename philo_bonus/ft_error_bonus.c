/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:57:22 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/02 01:46:31 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error(t_inf *ph, t_sem *sema, int *frk, int i)
{
	if (i == 1)
		ft_free_all(ph, ph[0].sem, frk);
	printf("Error\n");
	exit(EXIT_FAILURE);
}
