/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:51:40 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/21 03:17:04 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct t_infop
{
	int				i;
	int				ac;
	int				m_eat;
	long int		start;
	int				s_sleep;
	int				t_sleep;
	int				t_eat;
	long int		l_meal;
	int				nph;
	int				index;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	struct t_infop			*phh;
}	t_inf;

typedef struct t_info
{
	t_inf		*ph;
}	t_list;

int	ft_error(int ac, char **av);
int	ft_atoi(const char *str);
void	*ft_routing(void *a);
long int	ft_get_time(void);

#endif
