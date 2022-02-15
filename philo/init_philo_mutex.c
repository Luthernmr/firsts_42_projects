/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:25:27 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/15 18:08:23 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_setup *setup)
{
	int	i;

	i = setup->number_of_philosophers;
	setup->mutex_fork = malloc(sizeof(pthread_mutex_t)
			* setup->number_of_philosophers);
	while (--i >= 0)
		pthread_mutex_init(&(setup->mutex_fork[i]), NULL);
	pthread_mutex_init(&(setup->mutex_message), NULL);
	pthread_mutex_init(&(setup->mutex_eat), NULL);
	pthread_mutex_init(&(setup->mutex_sleep), NULL);
}

void	init(t_setup *setup, char **argv)
{
	int	i;

	i = -1;
	setup->time = get_time(setup);
	setup->number_of_philosophers = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		setup->nb_must_eat = ft_atoi(argv[5]);
	setup->philo = malloc (sizeof(t_philo) * setup->number_of_philosophers);
	setup->someone_died = 0;
	while (++i < setup->number_of_philosophers)
	{
		setup->philo[i].eat = 0;
		setup->philo[i].id = 0;
		setup->philo[i].time_last_meal = 0;
		setup->philo[i].die = 0;
		setup->philo[i].think = 0;
		setup->philo[i].sleep = 0;
		setup->philo[i].fork_left = i;
		setup->philo[i].fork_right = (i + 1) % setup->number_of_philosophers;
		setup->philo[i].setup = setup;
	}
	init_mutex(setup);
}
