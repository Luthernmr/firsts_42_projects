/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:02:37 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/18 15:52:21 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//int	check_one_philo(t_philo *philo, t_setup *setup)
//{
//	if (philo->fork_left == philo->fork_right)
//	{
//		pthread_mutex_lock(&(setup->mutex_die));
//		setup->someone_died = 1;
//		pthread_mutex_unlock(&(setup->mutex_die));
//		philo_die_msg(philo);
//		return (1);
//	}
//	return (0);
//}

int	philo_eat(t_philo *philo)
{
	t_setup	*setup;

	setup = philo->setup;
	pthread_mutex_lock(&(setup->mutex_fork[philo->fork_left]));
	philo_take_fork(philo);
	if (philo->fork_left == philo->fork_right)
		return (1);
	pthread_mutex_lock(&(setup->mutex_fork[philo->fork_right]));
	philo_take_fork(philo);
	philo->eat += 1;
	pthread_mutex_lock(&(setup->mutex_last_meal));
	philo->time_last_meal = get_time(setup) - setup->time;
	pthread_mutex_unlock(&(setup->mutex_last_meal));
	philo_eat_msg(philo);
	pthread_mutex_lock(&(setup->mutex_eat));
	if (philo->eat == setup->nb_must_eat)
		setup->finish_eat += 1;
	pthread_mutex_unlock(&(setup->mutex_eat));
	pthread_mutex_unlock(&(setup->mutex_fork[philo->fork_left]));
	pthread_mutex_unlock(&(setup->mutex_fork[philo->fork_right]));
	return (0);
}

void	check_philo_die(t_setup *setup)
{
	int	i;

	while (!(check_value(setup, &setup->mutex_die, 'd') == 1)
		&& !(check_value(setup, &setup->mutex_eat, 'e')
			== setup->number_of_philosophers))
	{
		i = 0;
		while (i < setup->number_of_philosophers)
		{
			if ((get_time(setup) - setup->time)
				- check_value_2(&setup->philo[i],
					&setup->mutex_last_meal, 'l') > setup->time_to_die)
			{
				pthread_mutex_lock(&(setup->mutex_die));
				setup->someone_died = 1;
				pthread_mutex_unlock(&(setup->mutex_die));
				philo_die_msg(&setup->philo[i]);
				break ;
			}
			if (check_value(setup, &setup->mutex_eat, 'e')
				== setup->number_of_philosophers)
				break ;
			i++;
		}
	}
}

void	*routine_philo(void *phi)
{
	t_philo			*philo;
	t_setup			*setup;	
	int				i;

	i = 0;
	philo = (t_philo *)phi;
	setup = philo->setup;
	if (philo->id % 2 && !(setup->number_of_philosophers == 1))
	{
		philo_think(philo);
		usleep(10000);
	}
	while (!(check_value(setup, &setup->mutex_die, 'd') == 1)
		&& !(check_value(setup, &setup->mutex_eat, 'e')
			== setup->number_of_philosophers))
	{
		if (philo_eat(philo) == 0)
		{
			philo_sleep(philo);
			philo_think(philo);
		}
		else
			return (NULL);
	}
	return (NULL);
}
