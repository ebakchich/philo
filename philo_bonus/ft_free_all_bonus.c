/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 05:19:38 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/25 07:42:37 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free_all(t_inf *ph, t_sem *sema, int *frk)
{
	sem_close(sema->forks);
	sem_close(sema->lock_print);
	sem_unlink("forks");
	sem_unlink("lock_print");
	free(sema);
	free(frk);
	free(ph);
}
