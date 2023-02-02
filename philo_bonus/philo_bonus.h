/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:20:32 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/02 01:43:59 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct t_sem
{
	sem_t	*forks;
	sem_t	*lock_print;
}	t_sem;

typedef struct t_infop
{
	int				ac;
	int				m_eat;
	long int		start;
	long int		t_die;
	long int		s_sleep;
	int				t_sleep;
	int				t_eat;
	long int		l_meal;
	int				nph;
	int				index;
	t_sem			*sem;
}	t_inf;

int			ft_error(int ac, char **av);
int			ft_atoi(const char *str);
void		error(t_inf *ph, t_sem *sema, int *frk, int i);
void		ft_child(t_inf *ph);
long int	ft_get_time(void);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		ft_free_all(t_inf *ph, t_sem *sema, int *frk);

#endif
