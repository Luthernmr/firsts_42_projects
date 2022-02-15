/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:04:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/15 22:01:21 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	t_setup	*setup;

	setup = philo->setup;
	pthread_mutex_lock(&(setup->mutex_fork[philo->fork_left]));
	philo_take_fork(philo);
	pthread_mutex_lock(&(setup->mutex_fork[philo->fork_right]));
	philo_take_fork(philo);
	philo->eat += 1;
	if (philo->eat == setup->nb_must_eat)
		setup->finish_eat += 1;
	philo->time_last_meal = (get_time(setup) - setup->time);
	philo_eat_msg(philo);
	pthread_mutex_unlock(&(setup->mutex_fork[philo->fork_left]));
	pthread_mutex_unlock(&(setup->mutex_fork[philo->fork_right]));
	return (0);
}

void	check_philo_die(t_setup *setup)
{
	int	i;

	i = 0;
	while (!(setup->someone_died == 1)
		&& !(setup->finish_eat == setup->number_of_philosophers))
	{
		i = 0;
		while (i < setup->number_of_philosophers)
		{
			if ((get_time(setup) - setup->time)
				- setup->philo[i].time_last_meal > setup->time_to_die)
			{
				setup->someone_died = 1;
				philo_die_msg(&setup->philo[i]);
				break ;
			}
			if (setup->finish_eat == setup->number_of_philosophers)
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
	if (philo->id % 2 == 0)
	{
		usleep(2000);
		philo_think(philo);
	}
	while (!(setup->someone_died == 1)
		&& !(setup->finish_eat == setup->number_of_philosophers))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int			i;
	t_setup		setup;

	if (argc < 5 && argc > 6)
		return (0);
	if (ft_atoi(argv[1]) <= 0)
		return (0);
	init(&setup, argv);
	i = 0;
	while (i < setup.number_of_philosophers)
	{
		pthread_create(&(setup.philo[i].thread_id), NULL,
			&routine_philo, &(setup.philo[i]));
		setup.philo[i].id = i + 1;
		i++;
	}
	i = 0;
	check_philo_die(&setup);
	while (i < setup.number_of_philosophers)
		pthread_join(setup.philo[i++].thread_id, NULL);
	i = 0;
	while (i < setup.number_of_philosophers)
		pthread_mutex_destroy(&(setup.mutex_fork[i++]));
	return (0);
}
