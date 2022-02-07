/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:04:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/07 18:21:43 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->setup->mutex_fork[philo->fork_left]));
	printf("philo %d has take lfork %d\n", philo->id, philo->fork_left);
	pthread_mutex_lock(&(philo->setup->mutex_fork[philo->fork_right]));
	printf("philo %d has take rfork %d\n", philo->id, philo->fork_right);
	pthread_mutex_lock(&(philo->setup->mutex_eat));
	philo->eat = 1;
	printf("eat\n");
	philo->eat = 0;
	pthread_mutex_unlock(&(philo->setup->mutex_eat));
	pthread_mutex_unlock(&(philo->setup->mutex_fork[philo->fork_left]));
	pthread_mutex_unlock(&(philo->setup->mutex_fork[philo->fork_right]));
	return (NULL);
}

void	*routine_philo(void *phi)
{
	t_philo			*philo;
	int				i;

	i = 0;
	philo = (t_philo *)phi;
	if (philo->id % 2 == 0)
		usleep(15000);
	if (philo->setup->someone_died == 0)
	{
		philo_eat(philo);
	}
	return (NULL);
}

//void	*do_eat(void *data)

int	main(int argc, char **argv)
{
	int			i;
	int			res;
	t_setup		setup;

	res = 0;
	i = 0;
	if (argc != 2)
		return (0);
	setup.number_of_philosophers = ft_atoi(argv[1]);
	setup.philo = malloc (sizeof(t_philo) * setup.number_of_philosophers);
	setup.someone_died = 0;
	while (i < setup.number_of_philosophers)
	{
		dprintf(1, "philo_id : %d | ", setup.philo[i].id);
		setup.philo[i].eat = 0;
		setup.philo[i].die = 0;
		setup.philo[i].think = 0;
		setup.philo[i].sleep = 0;
		setup.philo[i].fork_left = i;
		dprintf(1, "fork_l : %d | ", setup.philo[i].fork_left);
		setup.philo[i].fork_right = (i + 1) % setup.number_of_philosophers;
		setup.philo[i].setup = &setup;
		dprintf(1, "fork_r : %d\n", setup.philo[i].fork_right);
		i++;
	}
	setup.mutex_fork = malloc(sizeof(pthread_mutex_t) * setup.number_of_philosophers);
	i = 0;
	while (i < setup.number_of_philosophers)
	{
		pthread_create(&(setup.philo[i].thread_id), NULL,
			&routine_philo, &(setup.philo[i]));
		setup.philo[i].id = i + 1;
		usleep(20);
		i++;
	}

	
	return (0);
}
