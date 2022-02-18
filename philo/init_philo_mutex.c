/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:25:27 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/18 16:32:40 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_setup *setup)
{
	int	i;

	i = setup->number_of_philosophers;
	while (--i >= 0)
		pthread_mutex_init(&(setup->mutex_fork[i]), NULL);
	pthread_mutex_init(&(setup->mutex_message), NULL);
	pthread_mutex_init(&(setup->mutex_eat), NULL);
	pthread_mutex_init(&(setup->mutex_last_meal), NULL);
	pthread_mutex_init(&(setup->mutex_die), NULL);
	return (0);
}

int	init_time(t_setup *setup, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_atoi(argv[i]) == -1)
			return (-1);
		i++;
	}
	setup->time = get_time(setup);
	setup->finish_eat = 0;
	setup->number_of_philosophers = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		setup->nb_must_eat = ft_atoi(argv[5]);
	return (0);
}

int	init(t_setup *setup, char **argv)
{
	int	i;

	i = -1;
	if (init_time(setup, argv) == -1)
		return (-1);
	if (argv[5])
		setup->nb_must_eat = ft_atoi(argv[5]);
	setup->someone_died = 0;
	while (++i < setup->number_of_philosophers)
	{
		setup->philo[i].eat = 0;
		setup->philo[i].id = i + 1;
		setup->philo[i].time_last_meal = 0;
		setup->philo[i].die = 0;
		setup->philo[i].think = 0;
		setup->philo[i].sleep = 0;
		setup->philo[i].fork_left = i;
		setup->philo[i].fork_right = (i + 1) % setup->number_of_philosophers;
		setup->philo[i].setup = setup;
	}
	init_mutex(setup);
	return (0);
}
