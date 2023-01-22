/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:51:40 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/22 20:55:01 by ebakchic         ###   ########.fr       */
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
	int				ac;
	int				m_eat;
	long int		start;
	long int		t_die;
	int				s_sleep;
	int				t_sleep;
	int				t_eat;
	long int		l_meal;
	int				nph;
	int				index;
	pthread_mutex_t	*forks;
}	t_inf;

int			ft_error(int ac, char **av);
int			ft_atoi(const char *str);
void		*ft_routing(void *a);
long int	ft_get_time(void);
size_t		ft_strlen(const char *s);
void		ft_print_msg(t_inf *ph, char *str);

#endif
