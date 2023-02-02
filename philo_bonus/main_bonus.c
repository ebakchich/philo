/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:20:57 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/02 02:09:02 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_sema(t_sem *sema, int i, t_inf *ph)
{
	sem_unlink("forks");
	sem_unlink("lock_print");
	sema->forks = sem_open("forks", O_CREAT, 0666, i);
	if (sema->forks == SEM_FAILED)
		error(ph, sema, NULL, 1);
	sema->lock_print = sem_open("lock_print", O_CREAT, 0666, 1);
	if (sema->forks == SEM_FAILED)
		error(ph, sema, NULL, 1);
}

void	ft_fill(t_inf *ph, char **av, int ac)
{
	int				i;
	t_sem			*sema;
	int				index;

	i = 0;
	index = ft_atoi(av[1]);
	sema = malloc(sizeof(t_sem));
	while (i < index)
	{
		ph[i].t_eat = ft_atoi(av[3]);
		ph[i].t_sleep = ft_atoi(av[4]);
		ph[i].sem = sema;
		ph[i].index = i;
		ph[i].nph = index;
		ph[i].ac = ac;
		if (ph[i].ac == 6)
			ph[i].m_eat = ft_atoi(av[5]);
		ph[i].t_die = ft_atoi(av[2]);
		i++;
	}
	ft_init_sema(sema, ph->nph, ph);
}

void	ft_check_child(t_inf *ph, int *frk, int status)
{
	int	i;

	i = 0;
	while (i < ph[0].nph)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			i = 0;
			while (i < ph[0].nph)
			{
				kill(frk[i], SIGKILL);
				i++;
			}
			return ;
		}
		i++;
	}
}

void	ft_creat_philo(int ac, char **av)
{
	t_inf		*ph;
	int			*frk;
	int			status;
	int			i;
	int			k;

	ph = malloc(ft_atoi(av[1]) * sizeof(t_inf));
	ft_fill(ph, av, ac);
	frk = malloc(ph[0].nph * sizeof(int));
	i = 0;
	ph[0].start = ft_get_time();
	while (i < ph[0].nph)
	{
		ph[i].start = ph[0].start;
		ph[i].l_meal = ph[0].start;
		frk[i] = fork();
		if (frk[i] == -1)
			error(ph, ph[0].sem, frk, 1);
		if (frk[i] == 0)
			ft_child(&ph[i]);
		usleep(1);
		i++;
	}
	ft_check_child(ph, frk, status);
	ft_free_all(ph, ph[0].sem, frk);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
		error(NULL, NULL, NULL, 0);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (((av[i][j] < 48 || av[i][j] > 57) && av[i][j] != '+')
				|| ft_atoi(av[i]) < 0)
				error(NULL, NULL, NULL, 0);
			j++;
		}
		i++;
	}
	if (ac == 6)
		if (ft_atoi(av[5]) == 0)
			return (0);
	if (ft_atoi(av[1]) == 0)
		return (0);
	ft_creat_philo(ac, av);
	return (0);
}
