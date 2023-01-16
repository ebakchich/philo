/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:51:40 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/15 20:57:31 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>

typedef struct t_infop
{
	int	i;
}	t_inf;

typedef struct t_info
{
	int		nph;
	t_infop	*ph;
}   t_list;

int ft_error(int ac, char **av);
int	ft_atoi(const char *str);

#endif
