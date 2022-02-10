/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:04:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/10 17:40:36 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_setup *setup)
{
	long	t;

	gettimeofday(&setup->current_time, NULL);
	t = setup->current_time.tv_sec * 1000 + setup->current_time.tv_usec / 1000;
	return (t);
}

void	*philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->setup->mutex_fork[philo->fork_left]));
	printf("fork left %d\n", &(philo->setup->mutex_fork[philo->fork_left]));
	printf("%ld %d has taken a fork\n", get_time(philo->setup)
		- philo->setup->time, philo->id);
	pthread_mutex_lock(&(philo->setup->mutex_fork[philo->fork_right]));
	printf("%ld %d has taken a fork\n", get_time(philo->setup)
		- philo->setup->time, philo->id);
	pthread_mutex_lock(&(philo->setup->mutex_eat));
	philo->eat = 1;
	printf("%ld %d is eating\n", get_time(philo->setup)
		- philo->setup->time, philo->id);
	philo->time_last_meal = get_time(philo->setup);
	usleep(philo->setup->time_to_eat * 1000);
	philo->eat = 0;
	pthread_mutex_unlock(&(philo->setup->mutex_eat));
	pthread_mutex_unlock(&(philo->setup->mutex_fork[philo->fork_left]));
	pthread_mutex_unlock(&(philo->setup->mutex_fork[philo->fork_right]));
	return (NULL);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->setup->mutex_sleep));
	printf("%ld %d is sleeping\n", get_time(philo->setup)
		- philo->setup->time, philo->id);
	usleep(philo->setup->time_to_sleep * 1000);
	pthread_mutex_unlock(&(philo->setup->mutex_sleep));
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->setup->mutex_think));
	printf("%ld %d is thinking\n", get_time(philo->setup)
		- philo->setup->time, philo->id);
	pthread_mutex_unlock(&(philo->setup->mutex_think));
}

void	*routine_philo(void *phi)
{
	t_philo			*philo;
	int				i;

	i = 0;
	philo = (t_philo *)phi;
	if (philo->id % 2 == 0)
		usleep(150000);
	while ((get_time(philo->setup) - philo->setup->time)
		< philo->setup->time_to_die)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	while (i < philo->setup->number_of_philosophers)
	{
		if (philo->setup->philo[i].die == 1)
			printf("he die");
		i++;
	}
	return (NULL);
}

void	init(t_setup *setup, char **argv)
{
	int	i;

	i = 0;
	setup->time = get_time(setup);
	setup->number_of_philosophers = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	setup->philo = malloc (sizeof(t_philo) * setup->number_of_philosophers);
	setup->someone_died = 0;
	while (i < setup->number_of_philosophers)
	{
		dprintf(1, "philo_id : %d | ", setup->philo[i].id);
		setup->philo[i].eat = 0;
		setup->philo[i].die = 0;
		setup->philo[i].think = 0;
		setup->philo[i].sleep = 0;
		setup->philo[i].fork_left = i;
		dprintf(1, "fork_l : %d | ", setup->philo[i].fork_left);
		setup->philo[i].fork_right = (i + 1) % setup->number_of_philosophers;
		setup->philo[i].setup = setup;
		dprintf(1, "fork_r : %d\n", setup->philo[i].fork_right);
		i++;
	}
	setup->mutex_fork = malloc(sizeof(pthread_mutex_t)
			* setup->number_of_philosophers);
}

int	main(int argc, char **argv)
{
	int			i;
	t_setup		setup;

	if (argc != 5)
		return (0);
	init(&setup, argv);
	i = 0;
	while (i < setup.number_of_philosophers)
	{
		pthread_create(&(setup.philo[i].thread_id), NULL,
			&routine_philo, &(setup.philo[i]));
		setup.philo[i].id = i + 1;
		// usleep(1000000);
		i++;
	}
	i = 0;
	while (i < setup.number_of_philosophers)
		pthread_join(setup.philo[i++].thread_id, NULL);
	return (0);
}
